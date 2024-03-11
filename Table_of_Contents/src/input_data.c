#include "input_data.h"

int
get_input( inputData_t* inputData, char* fileName )
{
        FILE*                   file = fopen( fileName, "r" );

        if ( file == NULL )
        {
                printf( "Uh oh, could not open file %s!\n", fileName );
                strerror( errno );
                return 1;
        }

        char*                   buffer = ( char* ) malloc( BUF_SIZE * sizeof( char* ) );

        /*
                Each input file should have the line count of the
                input as the first line, so we read that first.
         */

        fgets( buffer, BUF_SIZE, file );
        inputData->lineCount = atoi( buffer );

        if ( inputData->lineCount == 0 )
        {
                printf( "Line count of input file is 0! No data to read!\n" );
                return 1;
        }

        inputData->data = ( char** ) malloc( ( inputData->lineCount ) * sizeof( char* ) );

        for ( int i = 0; i <= inputData->lineCount; i++ )
        {
                fgets( buffer, BUF_SIZE, file );

                inputData->data[ i ] = ( char* ) malloc( strlen( buffer ) * sizeof( char ) );

                memcpy( inputData->data[ i ], buffer, strlen( buffer ) * sizeof( char ) );
        }

        free( buffer );

        fclose( file );

        return 0;
}

int
input_data_free( inputData_t *inputData )
{
        for( int i = 0; i < inputData->lineCount; i++ )
        {
                free( inputData->data[ i ] );
        }
        
        free( inputData );

        return 0;
}

