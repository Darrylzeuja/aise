#include <mylib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int i = 10;

	printf("fact(%llu) = %llu\n", i, compute_fact(i));
	return 0;
}
