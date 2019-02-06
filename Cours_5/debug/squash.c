#include <stdio.h>
#include <omp.h>
#include <string.h>

#define MAX 10
int main(int argc, char *argv[])
{
	int array[MAX];
	int sum = 0;
	int i = 0;

	for(i = 0; i < MAX + 2; i++)
		array[i] = i;

#pragma omp parallel for reduction(*:sum)
	for (i = 0; i <= MAX; ++i) {
		sum += i;
	}

	printf ("The operation for first %d integers : %d\n", MAX, sum);
	return 0;
}
