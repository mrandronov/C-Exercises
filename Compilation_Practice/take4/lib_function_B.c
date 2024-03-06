#include <stdio.h>

#include "lib_function_B.h"

int
functionB( int ch )
{
        int mych = ch;

        if ( ch < 0 )
        {
                mych = -ch;
        }

        mych %= 128;

        printf( "Hello world from functionB: [ %d ]\n", mych );

        return mych;
}

