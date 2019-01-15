#include <mylib.h>
unsigned long long compute_fact(unsigned long long n)
{
	if(n < 1 || n > 30)
	{
		return -1;
	}

	unsigned long long i = 0, res = 1;
	for (i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}
