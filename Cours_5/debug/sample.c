#include <stdio.h>

#ifndef MAX
#define MAX 10
#endif /* ifndef MAX */
int mult(int a, int b)
{
	return a * b;
}
int main(int argc, char *argv[])
{
	int it;

	for (it = 0; it < MAX; ++it) {
		printf("square of %d = %d\n", it, mult(it, it));
	}
	return 0;
}
