#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
int fputs(const char * restrict s, FILE *restrict stream)
{
	static int(*func)(const char*, FILE*) = NULL;
	
	if(!func)
		func = (int(*)(const char*, FILE*))dlsym(RTLD_NEXT, "fputs");

	printf("Length = %zu\n", strlen(s));
	return func(s, stream);
}
int puts(const char *s)
{
	static int(*func)(const char*) = NULL;
	
	if(!func)
		func = (int(*)(const char*))dlsym(RTLD_NEXT, "puts");

	printf("Length = %zu\n", strlen(s));
	return func(s);
}
