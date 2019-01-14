#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	size_t sum = 0;
	int i = 0;
	int size = 10;

	if(argc >= 2)
		size = atoi(argv[1]);

#pragma omp parallel for reduction(+:sum)
	for (i = 1; i <= size; ++i) {
		sum += i;
	}

	printf("Sum of first %d integers = %zd\n", size, sum );
	return 0;
}
