#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mycommon.h"

int main( int argc, char **argv )
{
    int *p = NULL;
    
    if( argc != 2 )
    {
        printf( "Nepravilan unos\n" );
        exit( EXIT_FAILURE );
    };
    
    p = ( int * ) malloc( sizeof( int ) );
    if( p == NULL ) exit( EXIT_FAILURE );
    
    printf( "[%d] pointer p at address: %p points to address: %p\n", ( int ) getpid(), &p, p );
    
    *p = atoi( *( argv + 1 ) );
    
    while( 1 )
    {
        printf( "val: %d\n", *p );
        ( *p )++;
    };
    
    return 0;
}
