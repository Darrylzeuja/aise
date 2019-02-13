#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	char * v = strdup("toto");
	v[0] = 'l';
	printf("v = %s\n", v);
	free(v);
	return 0;
}
