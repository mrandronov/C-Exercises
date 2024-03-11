#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "input_data.h"
#include "table_of_contents.h"

int
main( int argc, char* argv[] )
{
        if ( argc < 2 )
        {
                printf( "Not enough args!\n" );
                exit( 1 );
        }

        int*                    resultCount = ( int* ) malloc( sizeof( int ) );
        inputData_t*            inputData = ( inputData_t* ) malloc( sizeof( inputData_t ) );

        if( get_input( inputData, argv[ 1 ] ) != 0 )
        {
                return 1;
        }

        char**                  result = get_toc( inputData->lineCount, inputData->data, resultCount );

        /*
                Print out the table of contents to standard out for viewing.
         */

        for( int i = 0; i < *resultCount; i++ )
        {
                printf( "%s\n", result[ i ] );
        }

        /*
                Free the allocated structs.
         */

        input_data_free( inputData );

        for( int i = 0; i < *resultCount; i++ )
        {
                free( result[ i ] );
        }
        
        free( result );

        return 0;
}

