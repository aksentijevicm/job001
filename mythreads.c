#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int br = 0;
int loops;

void *worker( void *arg )
{
    int i;
    
    for( i = 0 ; i < loops ; i++ )
    {
        br = br + 2;
        br = br - 1;
        br = br + 0;
    };
    
    return NULL;
}

int main( int argc, char **argv )
{
    if( argc != 2 )
    {
        printf( "usage: ./mythread <loops>" );
        exit( -1 );
    };
    
    loops = atoi( *( argv + 1 ) );
    pthread_t p1, p2;
    
    printf( "counter initial value: %d\n", br );
    
    pthread_create( &p1, NULL, &worker, NULL );
    pthread_create( &p2, NULL, &worker, NULL );
    
    pthread_join( p1, NULL );
    pthread_join( p2, NULL );
    
    printf( "counter final value: %d\n", br );
    
    return 0;
}
