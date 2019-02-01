#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int shm = shm_open("/test_shm", O_RDWR | O_CREAT, 0600 );

	if( shm < 0)
	{
		perror("shm_open");
		return 1;
	}

	ftruncate(shm, sizeof(int)*2);

	int *val = (int*) mmap(NULL, sizeof(int)*2, PROT_READ|PROT_WRITE, MAP_SHARED, shm, 0); 

	if( !val )
	{
		perror("mmap");
		return 1;
	}

	/* valeur de départ */
	val[0] = 1;
	val[1] = 0;

	while(val[0])
	{
		sleep(1);
		val[1]++;
	}

	close(shm);
	shm_unlink("/test_shm");


	return 0;
}
