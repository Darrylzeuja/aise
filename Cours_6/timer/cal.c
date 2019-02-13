#include "cycle.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


double  __ticks_per_second ; 

void calibrate()
{
	struct timeval tv_start, tv_end;
	gettimeofday( &tv_start , NULL );
	double start_ts = getticks();

	sleep(5);

	gettimeofday( &tv_end , NULL );
	double end_ts = getticks();

	double start_time = (tv_start.tv_usec) * 1.0e-06 + (tv_start.tv_sec) * 1.0;
	double end_time = (tv_end.tv_usec) * 1.0e-06 + (tv_end.tv_sec) * 1.0;


	__ticks_per_second = ( (double)(end_ts - start_ts) ) / ( end_time - start_time );

}


double ticks_in_sec(double ticks)
{
	return ticks/__ticks_per_second;
}

int main(int argc, char **argv)
{
	calibrate();

	printf("Ticks per sec is %g\n", __ticks_per_second);
	return 0;
}

