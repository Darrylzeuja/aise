#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char * sdup(char *src)
{
	int len = strlen(src);
	char *ret = malloc(len+1);
	memcpy(ret, src, len+1);
	return ret;
}


int main(){
	char * v = sdup("toto");
	
	v[0] = 'l';
	printf("v = %s\n", v);

	free(v);

	return 0;
}
