#include <stdio.h>

int mult(int a, int b)
{
	return a * b;
}
int main(int argc, char *argv[])
{
	int i = 10;
	int j = 20;

	printf("mult = %d\n", mult(i, j));
	return 0;
}
