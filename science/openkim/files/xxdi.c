/***************************************************************************
 *  Description:
 *      Simulate functionality of "xxd -i", which outputs a C char array
 *      definition containing the bytes of a file.  The xxd command is part of
 *      the vim editor package, which is an undesirably large dependency for
 *      other packages that only require this feature of xxd.
 *
 *  Arguments:
 *      Filename to be dumped in hex.
 *
 *  Returns:
 *      EX_OK on success
 *      EX_NOINPUT if file cannot be read
 *      EX_USAGE if wrong number of arguments provided
 *
 *  History: 
 *  Date        Name        Modification
 *  2014-12-11  Jason Bacon Begin
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <sysexits.h>

int     main(int argc,char *argv[])

{
    int     ch, count;
    char    *file_name,
	    *array_name,
	    *p;
    FILE    *fp;
    
    switch(argc)
    {
	case    2:
	    file_name = argv[1];
	    break;
	default:
	    fprintf(stderr,"Usage: %s file_name\n",argv[0]);
	    return EX_USAGE;
    }

    if ( (fp = fopen(file_name, "r")) != NULL )
    {
	array_name = strdup(file_name);
	for (p = array_name; *p != '\0'; ++p)
	    if ( (*p == '.') || (*p == '/') )
		*p = '_';
	printf("unsigned char %s[] = {\n", array_name);
	for (count = 1; (ch = getc(fp)) != EOF; ++count )
	{
	    printf(" 0x%02x,", ch);
	    if ( count % 12 == 0 )
		putchar('\n');
	}
	puts("\n};");
	printf("unsigned int %s_len = %u;\n", array_name, count-1);
	fclose(fp);
	return EX_OK;
    }
    else
    {
	fprintf(stderr, "Unable to open %s.\n", file_name);
	return EX_NOINPUT;
    }
}

