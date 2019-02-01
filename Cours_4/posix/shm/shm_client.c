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

	int *val = (int*) mmap(NULL,
			       sizeof(int)*2,
			       PROT_READ|PROT_WRITE,
			       MAP_SHARED,
			       shm,
			       0); 

	if( !val )
	{
		perror("mmap");
		return 1;
	}


	/* valeur de départ */
	int last_val = -1;
	while(1)
	{
		if( val[1] != last_val ){
			printf("Val is %d max is 60\n", val[1]);
			last_val = val[1];

			/* Stop condition */
			if( 60 <= val[1] )
			{
				val[0] = 0;
				break;
			}
		}
		else
		{
			usleep(100);
		}

	}

	/* Unmap segment */
	close(shm);

	return 0;
}
