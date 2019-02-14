#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "ppm.h"
 
 
#define TRSH 2.0
#define ITER 1024ull
 
#define SIZEX 1500
#define SIZEY 1500
 
double cx( int x )
{
    /* -2 ---> 1 */
    static const double qx = 3.0 / (double)SIZEX;
    return -2.0 +  x * qx;
}
 
double cy( int y )
{
    /* -1 ---> 1 */
    static const double qy = 2.0 / (double)SIZEY;
    return -1.0 + y * qy;
}
 
int main(int argc, char *argv[])
{
 
 
    return 0;
}
