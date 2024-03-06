#include <stdio.h>
#include <string.h>

int
functionA( const char* str )
{
        printf( "Hello world from functionA: [ %s ]\n", str );

        return strlen( str );
}

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

extern int
main( int argc, char* argv[] )
{
        int a = functionA( argv[ 0 ] );

        int b = functionB( -666 );

        printf( "Modified!\n" );

        return 0;
}

