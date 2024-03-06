#ifndef __LIB_MORSE_NUMBERS_H__
#define __LIB_MORSE_NUMBERS_H__

char*                   morse_number_chars[] = {

        /* 0 */ "-----", /* 1 */ ".----", /* 2 */ "..---", /* 3 */ "...--", /* 4 */ "....-", 
        /* 5 */ ".....", /* 6 */ "-....", /* 7 */ "--...", /* 8 */ "---..", /* 9 */ "----."

};

char*
get_num_morse_char( const char* p )
{
        return morse_number_chars[ *p - '0' ];
}

#endif /* __LIB_MORSE_NUMBERS_H__ */

