#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define error(i, ...) do { fprintf(stderr, __VA_ARGS__); exit(i); } while(0)

struct obj_s
{
	int a;
	float b;
};
struct obj_s inst;

int func(int a)
{
	int ret = a * a;
	return ret;
}
int main(int argc, char *argv[])
{

	inst.a = 2;
	inst.b = 42.;
	if(argc < 2)
	{
		error(42, "Need one argument and got %d\n", argc);
	}
	printf("Hello, World '%s'\n", argv[1]);	
	while(1) func(inst.b);
	return 0;
}
