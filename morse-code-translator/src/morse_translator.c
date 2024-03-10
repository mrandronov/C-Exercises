
#include "morse_translator.h"

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


/*
        copy_morse_char() will copy a letter's morse code
        representation to the output buffer, 'dst', and 
        update the position index, 'pos'.

        If the current character we are translating for is
        not the last character ( i.e, the next character is
        not the null terminator ), then we also add a space 
        to the output buffer, for formatting purposes.
 */

void
copy_morse_char( char* dst, const char* src, int* pos, char* morse_char )
{
        int morse_char_size = strlen( morse_char );
        strcpy( &dst[ *pos ], morse_char );

        if ( *(src+1) != '\0' )
        {
                strcpy( &dst[ *pos + morse_char_size ], " " );
        }

        *pos += morse_char_size + 1;
}

char*
get_morse_char( const char* ascii_char )
{
        if ( isdigit( *ascii_char ) )
        {
                return get_num_morse_char( ascii_char );
        }
        else if ( isalpha( *ascii_char ) )
        {
                return get_alpha_morse_char( ascii_char );
        }
        else if ( isPunctuation( ascii_char ) )
        {
                return get_punc_morse_char( ascii_char );
        }
        else if ( *ascii_char == ' ' )
        {
                return get_space_morse_char();
        }
        else
        {
                printf( "Error: input character %c is not a letter or digit!\n", *ascii_char );
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
atom( char* output, const char* input )
{
        int                     pos = 0;

        for( const char* p = input; *p != '\0'; p++ )
        {
                copy_morse_char( output, p, &pos, get_morse_char( p ) );
        }

        output[ pos - 1 ] = '\0';

        return output;
}

