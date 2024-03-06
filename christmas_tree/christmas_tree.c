#include <stdio.h>
#include <stdlib.h>


void
print_christmas_tree_facing_right( int height )
{
        if ( height == 0 )
        {
                return ;
        }

        for ( int i = 0; i <= height; i++ )
        {
                for ( int j = 0; j < i; j++ )
                {
                        printf( "*" );
                }

                for ( int j = 0; j < height-i; j++ )
                {
                        printf( " " );
                }

                printf( "\n" );
        }
        for ( int i = 1; i < height; i++ )
        {
                for ( int j = 0; j < height-i; j++ )
                {
                        printf( "*" );
                }

                for ( int j = 0; j < i; j++ )
                {
                        printf( " " );
                }

                printf( "\n" );
        }
        printf( "\n" );
}

void
print_christmas_tree_facing_left( int height )
{
        if ( height == 0 )
        {
                return ;
        }

        for ( int i = 0; i <= height; i++ )
        {
                for ( int j = 0; j < height-i; j++ )
                {
                        printf( " " );
                }

                for ( int j = 0; j < i; j++ )
                {
                        printf( "*" );
                }
                printf( "\n" );
        }
        for ( int i = 1; i < height; i++ )
        {
                for ( int j = 0; j < i; j++ )
                {
                        printf( " " );
                }

                for ( int j = 0; j < height-i; j++ )
                {
                        printf( "*" );
                }
                printf( "\n" );
        }
        printf( "\n" );
}

void
print_christmas_tree_upside_down( int height )
{
        if ( height == 0 )
        {
                return ;
        }

        int c = (height * 2) - 1;
        for ( int i = 0; i < height; i++ )
        {
                for ( int j = 0; j < i; j++ )
                {
                        printf( " " );
                }

                for ( int j = 0; j < c; j++ )
                {
                        printf( "*" );
                }
                c -= 2;
                printf( "\n" );
        }
        printf( "\n" );
}

void
print_christmas_tree( int height )
{
        if ( height == 0 )
        {
                return ;
        }

        int c = 1;
        for ( int i = 0; i < height; i++ )
        {
                for ( int j = 0; j < height-i-1; j++ )
                {
                        printf( " " );
                }

                for ( int j = 0; j < c; j++ )
                {
                        printf( "*" );
                }
                c += 2;
                printf( "\n" );
        }
        printf( "\n" );
}

int
main( int argc, char** argv )
{
        if (argc == 1)
        {
                printf( "No args!\n" );
                return 0;
        }

        int height = atoi( argv[1] );

        print_christmas_tree( height );

        print_christmas_tree_upside_down( height );

        print_christmas_tree_facing_left( height );

        print_christmas_tree_facing_right( height );

        return 0;
}
