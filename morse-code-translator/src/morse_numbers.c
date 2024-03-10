
#include "morse_numbers.h"

char*                   morse_number_chars[] = {

        /* 0 */ "-----", /* 1 */ ".----", /* 2 */ "..---", /* 3 */ "...--", /* 4 */ "....-", 
        /* 5 */ ".....", /* 6 */ "-....", /* 7 */ "--...", /* 8 */ "---..", /* 9 */ "----."

};

char*
get_num_morse_char( const char* ascii_char )
{
        return morse_number_chars[ *ascii_char - '0' ];
}

