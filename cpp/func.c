#include <base.h>

double compute_ec(double m, double v)
{
	return (m * compute_square(v) / 2);
}
