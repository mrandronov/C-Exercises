#ifndef __LIB_TABLE_OF_CONTENTS_H__
#define __LIB_TABLE_OF_CONTENTS_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char* get_format( char* markupHeading, char* prevHeading );

char** get_toc( int lineCount, char** text, int* resultCount );

#endif /* __LIB_TABLE_OF_CONTENTS_H__ */

