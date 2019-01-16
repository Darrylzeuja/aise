#include <stdio.h>
#include <string.h>

struct particle
{
	int x,y;
};

#define NUM_PART 64

int main(int argc, char ** argv )
{
	if(argc != 2)
		return 1;

	struct particle parts[NUM_PART];
	int i;

	FILE * inout = NULL;
	if(!strcmp(argv[1], "read"))
	{
		inout = fopen("./parts_s", "r");

		if(!inout)
		{
			perror("fopen");
			return 1;
		}

		for( i = 0 ; i < NUM_PART; i++)
			fscanf(inout,"%d %d\n", &parts[i].x, &parts[i].y);

		for( i = 0 ; i < NUM_PART; i++)
		{
			if( (parts[i].x != i) || (parts[i].y != (i + 1)) )
			{
				fprintf(stderr, "Erreur dans le buffer %d\n", i);
				fprintf(stderr, "x %d vs %d\n", parts[i].x, i);
				fprintf(stderr, "y %d vs %d\n", parts[i].y, i);
				return 1;
			}
		}

	}
	else if(!strcmp(argv[1], "write"))
	{
		inout = fopen("./parts_s", "w");

		if(!inout)
		{
			perror("fopen");
			return 1;
		}

		for( i = 0 ; i < NUM_PART; i++)
		{
			parts[i].x = i;
			parts[i].y = i + 1;
		}


		for( i = 0 ; i < NUM_PART; i++)
			fprintf(inout, "%d %d\n", parts[i].x, parts[i].y);




	}

	fclose(inout);
}

