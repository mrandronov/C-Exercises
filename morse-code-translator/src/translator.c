#include <stdio.h>
#include <stdlib.h>

#include "morse_translator.h"

int
main( int argc, char** argv )
{
        if ( argc != 2 )
        {
                printf( "Not enough args!\n" );
                return 1;
        }

        char*                   input = argv[ 1 ];
        char*                   output = ( char* ) malloc( get_output_size( input ) * sizeof( char ) );

        atom( output, input );

        printf( "Input: [%s]\n", input );
        printf( "Output: [%s]\n", output );

        free( output );
}

