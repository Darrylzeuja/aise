#include <stdio.h>


int main(int argc, char **argv)
{
	if(argc == 1)
		return 0;


	for(i = 1; i < argc; i++)
		unlink(argv[i]);
	

	return 0;
}
