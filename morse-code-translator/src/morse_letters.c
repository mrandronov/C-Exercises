
#include "morse_letters.h"

char*                   morse_letter_chars[] = {

        /* A */ ".-",   /* B */ "-...", /* C */ "-.-.", /* D */ "-..", 
        /* E */ ".",    /* F */ "..-.", /* G */ "--.",  /* H */ "....", 
        /* I */ "..",   /* J */ ".---", /* K */ "-.-",  /* L */ ".-..", 
        /* M */ "--",   /* N */ "-.",   /* O */ "---",  /* P */ ".--.", 
        /* Q */ "--.-", /* R */ ".-.",  /* S */ "...",  /* T */ "-", 
        /* U */ "..-",  /* V */ "...-", /* W */ ".--",  /* X */ "-..-", 
        /* Y */ "-.--", /* Z */ "--.."

};

char*
get_alpha_morse_char( const char* ascii_char )
{
        /*
                The alphabet is consecutive in ASCII, so we
                can just find the relevant index using the
                ASCII decimal encoding.

                Since Morse Code does not distinguish between
                upper and lower case letters, we always convert 
                the input character to upper case.
         */

        int             index = 0;

        if ( *ascii_char >= 97 )
        {
                /* p is lowercase */
                index = *ascii_char - 'a';
        }
        else
        {
                index = *ascii_char - 'A';
        }

        return morse_letter_chars[ index ];
}

