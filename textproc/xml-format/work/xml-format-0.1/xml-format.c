/***************************************************************************
 *  Description:
 *      Format and indent XML files
 *
 *  Arguments:
 *      XML filename
 *
 *  Returns:
 *      See sysexits.h
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-09  Jason Bacon Begin
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <sysexits.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "tag-list.h"
#include "xml-format.h"


int     main(int argc,char *argv[])

{
    switch(argc)
    {
	case    2:
	    break;
	default:
	    fprintf(stderr,"Usage: %s filename\n",argv[0]);
	    return EX_USAGE;
    }
    return xml_format(argv[1]);
}


/***************************************************************************
 *  Description:
 *      Format an XML document contained in filename.
 *
 *  Arguments:
 *      filename:   XML document to format.  Serves as both the
 *                  input and output file.  The original file is
 *                  saved as filename.bak.
 *  Returns:
 *      See sysexits.h
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-09  Jason Bacon Begin
 ***************************************************************************/

int xml_format(const char *filename)

{
    FILE    *infile,
	    *tempfile;
    int     status,
	    outfd;
    char    backup[PATH_MAX+1],
	    buff[COPY_BUFF_SIZE+1],
	    *subdir;
    size_t  bytes;
    extern int  errno;
    tag_list_t  tags;
    
    if ( ( subdir = strrchr(filename, '.')) == NULL )
    {
	fprintf(stderr, "Error: Filename must have an extension to indicate\n"
			"the file type (e.g. .dbk for DocBook).\n");
	return EX_USAGE;
    }
    
    tag_list_load(&tags, subdir+1);
    
    if ( (infile = fopen(filename,"r")) == NULL )
    {
	fprintf(stderr, "Error: Could not open %s for reading: %s\n",
	    filename, strerror(errno));
	return EX_NOINPUT;
    }
    
    if ( (tempfile = tmpfile()) == NULL )
    {
	fprintf(stderr, "Error: Could not open temporary file: %s\n",
	    strerror(errno));
	return EX_CANTCREAT;
    }
    
    status = process_file(infile, tempfile, 0, &tags);
    fclose(infile);
    
    if ( status == EX_OK )
    {
	snprintf(backup, PATH_MAX, "%s.bak", filename);
	if ( rename(filename, backup) != 0 )
	{
	    fprintf(stderr, "Error: Could not rename %s to %s: %s\n",
		filename, backup, strerror(errno));
	    return EX_CANTCREAT;
	}
	
	// Rewind temp file
	if ( fseek(tempfile, 0L, SEEK_SET) != 0 )
	{
	    fprintf(stderr, "Error: Could not rewind output file: %s\n",
		strerror(errno));
	    return EX_IOERR;
	}
	
	// Copy temp file back to original filename
	if ( (outfd = open(filename, O_WRONLY|O_CREAT, 0644)) == -1 )
	{
	    fprintf(stderr, "Error: Could not open %s for writing: %s\n",
		filename, strerror(errno));
	    return EX_CANTCREAT;
	}
	
	while ( (bytes = read(fileno(tempfile), buff, COPY_BUFF_SIZE)) > 0 )
	    write(outfd, buff, bytes);
	close(outfd);
    }
    
    return EX_OK;
}


/***************************************************************************
 *  Description:
 *      Perform XML formatting on the stream infile, writing the formatted
 *      text to stream outfile.
 *
 *  Arguments:
 *      infile:     input stream
 *      outfile:    output stream
 *      indent:     number of columns to indent each level
 *      tags:       list of tags specific to the XML language (e.g. DocBook)
 *
 *  Returns:
 *      See sysexits.h
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-09  Jason Bacon Begin
 ***************************************************************************/

int     process_file(FILE *infile, FILE *outfile, int indent, tag_list_t *tags)

{
    int     ch,
	    col = 0,
	    indent_step = 4;
    char    tag_name[MAX_TAG_LEN+1];
    char    output_buff[MAX_LINE_LEN+1];
    
    while ( (ch = getc(infile)) != EOF )
    {
	if ( ch == '<' )
	{
	    read_tag(infile, tag_name, MAX_TAG_LEN);
	    switch ( tag_type(tags, tag_name) )
	    {
		/*
		 *  If sectioning tag (chapter, section) change indent
		 *  and start new line.
		 */
		case    SECTIONING_TAG:
		    if ( *tag_name != '/' ) /* Closing tag */
		    {
			putc('\n', outfile);
			// Dump current line and put tag on next line
			flush_line(output_buff, infile, outfile, indent, &col);
			buffer_tag(output_buff, &col, tag_name);
			flush_line(output_buff, infile, outfile, indent, &col);
			INCREASE(indent, indent_step);
			flush_line(output_buff, infile, outfile, indent, &col);
		    }
		    else
		    {
			// Dump current line and put tag on next line
			DECREASE(indent,indent_step);
			flush_line(output_buff, infile, outfile, indent, &col);
			buffer_tag(output_buff, &col, tag_name);
			flush_line(output_buff, infile, outfile, indent, &col);
		    }
		    break;

		/*
		 *  If block tag (para, note, etc.) just start new line.
		 */
		case    BLOCK_TAG:
		    if ( *tag_name != '/' ) /* Closing tag */
		    {
			if ( ! buff_empty(output_buff, col) )
			    flush_line(output_buff, infile, outfile, indent, &col);
			putc('\n',outfile);
			buffer_tag(output_buff, &col, tag_name);
			flush_line(output_buff, infile, outfile, indent, &col);
		    }
		    else
		    {
			flush_line(output_buff, infile, outfile, indent, &col);
			buffer_tag(output_buff, &col, tag_name);
			flush_line(output_buff, infile, outfile, indent, &col);
		    }
		    break;
		
		case    LINE_TAG:
		    if ( *tag_name != '/' ) /* Closing tag */
		    {
			if ( ! buff_empty(output_buff, col) )
			    flush_line(output_buff, infile, outfile, indent, &col);
			buffer_tag(output_buff, &col, tag_name);
		    }
		    else
		    {
			buffer_tag(output_buff, &col, tag_name);
			flush_line(output_buff, infile, outfile, indent, &col);
		    }
		    break;
		
		case    COMMENT_TAG:
		    putc('\n',outfile);
		    buffer_tag(output_buff, &col, tag_name);
		    flush_line(output_buff, infile, outfile, indent, &col);
		    break;
		
		/*
		 *  If inline tag, do nothing.
		 */
		default:
		    buffer_tag(output_buff, &col, tag_name);
		    // This causes space to be swallowed after xref
		    //check_line_len(infile, outfile, output_buff, indent, &col);
	    }
	}
	else if ( isspace(ch) )
	{
	    output_buff[col] = ' ';
	    check_line_len(infile, outfile, output_buff, indent, &col);

	    if ( swallow_space(infile) == EOF )
	    {
		flush_line(output_buff, infile, outfile, indent, &col);
		return EX_OK;
	    }
	    ++col;
	}
	else
	    // Check for end of buff
	    output_buff[col++] = ch;
    }
    return EX_OK;
}


/***************************************************************************
 *  Description:
 *      Read a tag from an XML input stream.
 *
 *  Arguments:
 *      infile:         Stream of XML input
 *      tag_name_ptr:   char buffer to receive tag
 *      max_tag_len:    length of char buffer
 *
 *  Returns:
 *      See sysexits.h
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-09  Jason Bacon Begin
 ***************************************************************************/

int     read_tag(FILE *infile, char *tag_name_ptr, int max_tag_len)

{
    // FIXME: Check for MAX_TAG_LEN
    while ( (*tag_name_ptr = getc(infile)) != '>' )
	++tag_name_ptr;
    *tag_name_ptr = '\0';
    return EX_OK;
}


/***************************************************************************
 *  Description:
 *      Determine type of tag based on name and XML language (e.g. DocBook)
 *
 *  Arguments:
 *      tags:   Structure containing lists of block, line, and sectioning
 *              tags for the given language.
 *
 *  Returns:
 *      Enumerated value indicating block, line, sectioning, or inline tag.
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-09  Jason Bacon Begin
 ***************************************************************************/

tag_t   tag_type(tag_list_t *tags, const char *tag_name)

{
    int     c;
    
    if ( tag_name[0] == '!' )
	return COMMENT_TAG;
    
    /*
     *  Tag name may start at position 0 or 1 (after '/')
     */
    for (c = 0; c <= 1; ++c)
    {
	if ( bsearch(tag_name + c, tags->sectioning_tags, tags->sectioning_tag_count,
	    sizeof(char *), (int (*)(const void *,const void *))memptrcmp) != NULL )
	    return SECTIONING_TAG;
	
	if ( bsearch(tag_name + c, tags->block_tags, tags->block_tag_count,
	    sizeof(char *), (int (*)(const void *,const void *))memptrcmp) != NULL )
	    return BLOCK_TAG;
	
	if ( bsearch(tag_name + c, tags->line_tags, tags->line_tag_count,
	    sizeof(char *), (int (*)(const void *,const void *))memptrcmp) != NULL )
	    return LINE_TAG;
    }
    return INLINE_TAG;
}


/***************************************************************************
 *  Description:
 *      Output a line of formatted XML.
 *
 *  Arguments:
 *      output_buff:    char buffer containing accumulated formatted text
 *      infile:         Unformatted XML input stream
 *      outfile:        Formatted XML output stream
 *      indent:         Number of columns to indent each level
 *      *col:           Column where next character should be buffered
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-09  Jason Bacon Begin
 ***************************************************************************/

void    flush_line(char *output_buff, FILE *infile, FILE *outfile,
	    int indent, int *col)

{
    output_buff[*col] = '\0';
    if ( !strblank(output_buff) )
    {
	fputs(output_buff, outfile);
	putc('\n', outfile);
    }
    
    //fflush(stdout);
    // This is needed *almost* everywhere, so we put it in here and
    // compensate in the few exceptional cases
    swallow_space(infile);
    memset(output_buff, ' ', indent);
    *col = indent;
}


/***************************************************************************
 *  Description:
 *      Discard extra whitespace in the input stream.
 *
 *  Arguments:
 *      infile:     Input stream
 *
 *  Returns:
 *      First non-whitespace character read.
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-09  Jason Bacon Begin
 ***************************************************************************/

int     swallow_space(FILE *infile)

{
    int     ch;
    
    while ( isspace(ch = getc(infile)) )
	;
    if ( !feof(infile) )
	ungetc(ch, infile);
    return ch;
}


/***************************************************************************
 *  Description:
 *      Write a tag to the output buffer.
 *
 *  Arguments:
 *      output_buff:    char buffer containing an output line
 *      *col:           Column where next char should be written
 *      tag_name:       Name of tag, not including <>
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-10  Jason Bacon Begin
 ***************************************************************************/

void    buffer_tag(char *output_buff, int *col, const char *tag_name)

{
    int     len = strlen(tag_name);
    
    //fprintf(stderr, "*col = %d\n", *col);
    
    // FIXME: If current line is not blank, and tag won't fit within MAX_COLS,
    // flush the line first and put tag on next line, so that tags with
    // attributes are not broken up.
    snprintf(output_buff + *col, MAX_LINE_LEN - *col, "<%s>", tag_name);
    *col += len + 2;
}


/***************************************************************************
 *  Description:
 *      Return true if the buffer contains only whitespace.
 *
 *  Arguments:
 *      buff:   char buffer containing the line
 *      col:    Column where next character would be written.
 *
 *  Returns:
 *      True if buffer contains only whitespace up to buff[col].
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-11  Jason Bacon Begin
 ***************************************************************************/

int     buff_empty(char *buff, int col)

{
    buff[col] = '\0';
    return strblank(buff);
}


/***************************************************************************
 *  Description:
 *      See if it's time to break the current output line.
 *
 *  Arguments:
 *      infile:         Input XML stream
 *      outfile:        Output XML stream
 *      output_buff:    Buffer containing output
 *      indent:         Number of columns to indent each level
 *      *col:           Column where next char should be written
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-11  Jason Bacon Begin
 ***************************************************************************/

void    check_line_len(FILE *infile, FILE *outfile, char *output_buff,
			int indent, int *col)

{
    int     save_col, c;
    
    if ( *col > MAX_COLS - 2 )
    {
	/* 
	 *  Back up to last whitespace at a position < MAX_COLS and
	 *  break line there
	 */
	for (c = *col - 1;
	    (c > MAX_COLS) || ((c > 0) && !isspace(output_buff[c])); --c)
	    ;
	if ( c > 0 )
	{
	    save_col = *col;
	    *col = c;
	    flush_line(output_buff, infile, outfile, indent, col);
	    memmove(output_buff + *col, output_buff + c + 1, save_col - c);
	    *col += save_col - c - 1;
	}
	else
	{
	    flush_line(output_buff, infile, outfile, indent, col);
	}
    }
}

