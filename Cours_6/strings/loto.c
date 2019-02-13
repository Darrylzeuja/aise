#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	char * v = "toto";
	v[0] = 'l';
	printf("v = %s\n", v);

	return 0;
}
