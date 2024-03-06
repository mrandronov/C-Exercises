#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
        Morse code representations for english letters,
        numbers, and punctuation are stored in the
        following header files.
        
        Getter functions for Morse code representations
        are also stored therein.
 */

#include "morse_letters.h"
#include "morse_numbers.h"
#include "morse_punctuation.h"
#include "morse_space.h"


char*
toUpperCase( char* s )
{
        for( char* p = s; *p; p++ ) 
        {
                *p = toupper( *p );
        }

        return s;
}

/*
        copy_morse_char() will copy a letter's morse code
        representation to the output buffer, 'output', and 
        update the position index, 'pos'.

        If the current character we are translating for is
        not the last character ( i.e, the next character is
        not the null terminator ), then we also add a space 
        to the output buffer, for formatting purposes.
 */

void
copy_morse_char( const char* p, char* output, int* pos, char* morse_char )
{
        int morse_char_size = strlen( morse_char );
        strcpy( &output[ *pos ], morse_char );

        if ( *(p+1) != '\0' )
        {
                strcpy( &output[ *pos + morse_char_size ], " " );
        }

        *pos += morse_char_size + 1;
}

char*
get_morse_char( const char* p )
{
        if ( isdigit( *p ) )
        {
                return get_num_morse_char( p );
        }
        else if ( isalpha( *p ) )
        {
                return get_alpha_morse_char( p );
        }
        else if ( isPunctuation( p ) )
        {
                return get_punc_morse_char( p );
        }
        else if ( *p == ' ' )
        {
                return get_space_morse_char( p );
        }
        else
        {
                printf( "Error: input character %c is not a letter or digit!\n", *p );
                exit( 1 );
        }

        return "";
}

/*
        get_output_size() determines the size of the input
        after it would be translated to morse code.

        This is done by adding up the lengths of each
        character's morse code representation.

        An extra byte of space is added between each morse
        code character which, in the final translated string,
        is used for a literal space character ( a ' ' ). This 
        is done purely for formatting purposes.
 */
int
get_output_size( const char* input )
{
        int                     output_size = 0;

        for( const char* p = input; *p; p++ )
        {
                char* morse_char = get_morse_char( p );
                output_size += strlen( morse_char ) + 1;
        }

        return output_size;
}

char*
translator( const char* input )
{
        int                     pos = 0;
        int                     output_size = get_output_size( input );
        char*                   output = ( char* ) malloc( output_size );

        for( const char* p = input; *p != '\0'; p++ )
        {
                copy_morse_char( p, output, &pos, get_morse_char( p ) );
        }

        output[ pos - 1 ] = '\0';

        return output;
}

int
main( int argc, char** argv )
{
        if ( argc != 2 )
        {
                printf( "Not enough args!\n" );
                return 1;
        }

        char*                   input = argv[ 1 ];
        char*                   output = translator( input );

        printf( "Input: [%s]\n", input );
        printf( "Output: [%s]\n", output );

        free( output );
}

