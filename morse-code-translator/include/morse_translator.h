#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef __LIB_MORSE_TRANSLATOR_H__
#define __LIB_MORSE_TRANSLATOR_H__

int get_output_size( const char* input );

char* atom( char* output, const char* input );

#endif /* __LIB_MORSE_TRANSLATOR_H__ */

