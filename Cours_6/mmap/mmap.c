#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define SIZE 1024*4096

int main(){
	char * v = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	if( v == MAP_FAILED)
	{
		perror("mmap");
		return 1;
	}


	size_t i;

	for( i = 0 ; i < SIZE; i++ )
	{
		v[i] = i;
	}

	munmap(v, SIZE);

	return 0;
}
