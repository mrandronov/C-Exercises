#include "lib_function_A.h"
#include "lib_function_B.h"

extern int
main( int argc, char* argv[] )
{
        int a = functionA( argv[ 0 ] );

        int b = functionB( -666 );

        return 0;
}

