#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <sysexits.h>
#include "tag-list.h"
#include "protos.h"

/***************************************************************************
 *  Description:
 *  
 *  Arguments:
 *
 *  Returns:
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-10  Jason Bacon Begin
 ***************************************************************************/

size_t  read_string_list(const char *filename, char *str_array[],
	size_t max_strings, size_t max_strlen)

{
    size_t  list_size = 0;
    FILE    *infile;
    char    string[max_strlen+1];
    
    if ( (infile = fopen(filename, "r")) == NULL )
	return -1;
    while ( read_string(infile, string, max_strlen) != 0 )
    {
	str_array[list_size++] = strdup(string);
    }
    fclose(infile);
    qsort(str_array, list_size, sizeof(char *),
	(int (*)(const void *,const void *))strptrcmp);
    /*for (c = 0; c < list_size; ++c)
	puts(str_array[c]);*/
    return list_size;
}


/***************************************************************************
 *  Description:
 *  
 *  Arguments:
 *
 *  Returns:
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-10  Jason Bacon Begin
 ***************************************************************************/

size_t  read_string(FILE *infile, char *string, size_t max_strlen)

{
    char    *p;
    
    for (p = string; ( (*p = getc(infile)) != '\n' ); ++p)
	;
    *p = '\0';
    return p - string;
}


/***************************************************************************
 *  Description:
 *  
 *  Arguments:
 *
 *  Returns:
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-10  Jason Bacon Begin
 ***************************************************************************/

void    tag_list_error_check(int list_size, const char *path)

{
    extern int  errno;
    
    if ( list_size == -1 )
    {
	fprintf(stderr, "Unable to read %s: %s\n", path, strerror(errno));
	exit(EX_NOINPUT);
    }
}


int     tag_list_load(tag_list_t *tags, const char *subdir)

{
    char    path[PATH_MAX+1];
    
    snprintf(path, PATH_MAX, "%s/Config/%s/sectioning-tags.txt", DATADIR, subdir);
    tags->sectioning_tag_count = read_string_list(path,
	tags->sectioning_tags, MAX_TAGS, MAX_TAG_LEN);
    tag_list_error_check(tags->sectioning_tag_count, path);

    snprintf(path, PATH_MAX, "%s/Config/%s/block-tags.txt", DATADIR, subdir);
    tags->block_tag_count = read_string_list(path,
	tags->block_tags, MAX_TAGS, MAX_TAG_LEN);
    tag_list_error_check(tags->block_tag_count, path);

    snprintf(path, PATH_MAX, "%s/Config/%s/line-tags.txt", DATADIR, subdir);
    tags->line_tag_count = read_string_list(path,
	tags->line_tags, MAX_TAGS, MAX_TAG_LEN);
    tag_list_error_check(tags->line_tag_count, path);

    return EX_OK;
}


/***************************************************************************
 *  Description:
 *  
 *  Arguments:
 *
 *  Returns:
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-10  Jason Bacon Begin
 ***************************************************************************/

int     strptrcmp(char **s1, char **s2)

{
    return strcmp(*s1, *s2);
}


/***************************************************************************
 *  Description:
 *  
 *  Arguments:
 *
 *  Returns:
 *
 *  History: 
 *  Date        Name        Modification
 *  2013-02-10  Jason Bacon Begin
 ***************************************************************************/

int     memptrcmp(char *s1, char **s2)

{
    //printf("%s %d\n", s1, strlen(s1));
    return memcmp(s1, *s2, strlen(*s2));
}

