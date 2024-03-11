#include "table_of_contents.h"

/*
        Given a series of pound signs and the 
        previous table of contents string,
        generate the next table of contests string.
 */

int
get_num_sections( char* heading )
{
        int sectionCount = 0;
        char*                   p = heading;
        while ( *p )
        {
                if ( *p == '.' )
                {
                        sectionCount++;
                }
                p += 1;
        }
        return sectionCount;
}

char*
get_format( char* markupHeading, char* prevHeading )
{
        int                     markupHeadingLen = strlen( markupHeading );
        int                     prevHeadingLen = strlen( prevHeading );

        if ( prevHeadingLen == 0 )
        {
                return "1.";
        }

        /*
                If the length of the markup pound signs is larger than
                the number of sections in the heading, then we know that
                new section is being marked, so just add a '1.' to the end
                and return.
         */

        if ( markupHeadingLen > get_num_sections( prevHeading ) )
        {
                char*                   result = ( char* ) malloc( ( prevHeadingLen + 2 ) * sizeof( char ) ); 
                memcpy( result, prevHeading, prevHeadingLen * sizeof( char ) );
                
                sprintf( result, "%s%d.", result, 1 );

                return result;
        }

        char*           headingCopy = ( char* ) malloc( prevHeadingLen * sizeof( char ) );
        memcpy( headingCopy, prevHeading, prevHeadingLen * sizeof( char ) );

        int             headingPos = 0;
        int             markupIndex = 0;
        char*           lastSection = NULL;
        char*           curr = strtok( headingCopy, "." );

        /*
                Find the last section number that correlates with the
                markup. Here we, convert the section number to an integer, 
                increment, and reformat it with the previous section heading.
         */

        while( curr && markupIndex < markupHeadingLen )
        {
                if ( lastSection != NULL )
                {
                        headingPos += strlen( lastSection ) + 1;
                }
                lastSection = curr;
                
                curr = strtok( NULL, "." );

                markupIndex++;
        }

        char*   sectionNumStr = NULL;

        /*
                If the last character of the number is '9', then
                we know that incrmenting this value will require
                an extra byte of storage for a new digit.
         */

        if ( lastSection[ strlen( lastSection ) - 1 ] == '9' )
        {
                sectionNumStr = ( char* ) malloc( ( strlen( lastSection ) + 2 ) * sizeof( char ) );
        }
        else
        {
                sectionNumStr = ( char* ) malloc( ( strlen( lastSection ) + 1 ) * sizeof( char ) );
        }

        sprintf( sectionNumStr, "%d.", atoi( lastSection ) + 1 );

        char*                   result = ( char* ) malloc( ( headingPos + strlen( sectionNumStr ) + 2 ) * sizeof( char ) );

        memcpy( result, prevHeading, headingPos * sizeof( char ) );
        memcpy( result + ( headingPos * sizeof( char ) ), sectionNumStr, strlen( sectionNumStr ) * sizeof( char ) );

        free( headingCopy );
        free( sectionNumStr );

        return result;
}

char**
get_toc( int lineCount, char** text, int* resultCount )
{
        (*resultCount) = 0;

        for ( int i = 0; i < lineCount; i++ )
        {
                if ( text[ i ][ 0 ] == '#' )
                {
                        (*resultCount) += 1;
                }
        }

        int                     index = 0;
        char*                   header = "";
        char**                  result = ( char** ) malloc( ( *resultCount ) * sizeof( char * ) );

        for ( int i = 0; i < lineCount; i++ )
        {
                if ( text[ i ][ 0 ] == '#' )
                {
                        char*                   p = text[ i ];

                        while ( *p != ' ' && *p )
                        {
                                p++;
                        }

                        char*                   title = strtok( p+1, "\n" );
                        *p = '\0';

                        header = get_format( text[ i ], header );

                        result[ index ] = ( char* ) malloc( ( strlen( header ) + strlen( title ) + 2 ) * sizeof( char ) );

                        sprintf( result[ index ], "%s %s", header, title );

                        index++;
                }
        }

        return result;
}

