
#include "morse_punctuation.h"

/*
        What counts as punctuation varies
        depending on the language localization
        and Morse Code alphabets. For now, I'm
        only going to be implement what is 
        defined in single byte ascii characters.

        A future improvement would be to implement
        multi-byte character translation.
 */

#define NUM_MORSE_PUNCTUATION_CHARS 17

int                     morse_punc_lookup[] = {

       '.', ',', '?', '\'', 
       '!', '/', '(', ')', 
       '&', ':', ';', '=', 
       '+', '-', '_', '\'', 
       '$'

};

char*                   morse_punc_chars[] = {

        /* . */ ".-.-.-", /* , */ "--..--", /* ? */ "..--..", /* ' */ ".----.",
        /* ! */ "-.-.--", /* / */ "-..-.", /* ( */ "-.--.", /* ) */ "-.--.-",
        /* & */ ".-...", /* : */ "---...", /* ; */ "-.-.-.", /* = */ "-...-",
        /* + */ ".-.-.", /* - */ "-....-", /* _ */ "..--.-", /* " */ ".-..-.",
        /* $ */ "...-..-"

};

int
isPunctuation( const char* s )
{
        for ( int i = 0; i < NUM_MORSE_PUNCTUATION_CHARS; i++ )
        {
                if ( morse_punc_lookup[ i ] == *s )
                {
                        return 1;
                }
        }

        return 0;
}

int
getPunctuationIndex( const char* s )
{
        for ( int i = 0; i < NUM_MORSE_PUNCTUATION_CHARS; i++ )
        {
                if ( morse_punc_lookup[ i ] == *s )
                {
                        return i;
                }
        }

        return -1;
}

char*
get_punc_morse_char( const char* ascii_char )
{
        return morse_punc_chars[ getPunctuationIndex( ascii_char ) ];
}



