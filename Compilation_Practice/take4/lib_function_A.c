#include <stdio.h>
#include <string.h>

#include "lib_function_A.h"

int
functionA( const char* str )
{
        printf( "Hello world from functionA: [ %s ] just changed it.\n", str );

        return strlen( str );
}

