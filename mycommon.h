#ifndef __common_h
#define __common_h

#include <sys/time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

double GetTime()
{
   struct timeval t;
   assert( gettimeofday( &t, NULL ) == 0 );

   return ( double ) t.tv_sec + ( double ) t.tv_usec / 1e6;
}

int Spin( int secs )
{
   double t = GetTime();

   while( GetTime() - t < ( double ) secs )
   {
       printf( "%f\n", GetTime() - t );
   };
   
   return 0;
}

#endif
