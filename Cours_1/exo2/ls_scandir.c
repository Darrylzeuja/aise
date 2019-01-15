#include <stdio.h>
#include <dirent.h>
#include <regex.h>


int selection(const struct dirent * file)
{
	return 1;
}



int main(int argc, char ** argv )
{
	if( argc != 2)
	{
		fprintf(stderr, "Syntaxe %s PATH\n", argv[0]);
		return 1;
	}


	struct dirent ** list = NULL;

	int nb_file = scandir(argv[1], &list, selection, alphasort);

	if(nb_file < 0)
	{
		perror("scandir");
		return 1;
	}

	int i;
	
	for(i = 0 ; i < nb_file; i++ )
	{
		printf("%s\n", list[i]->d_name);
	}

	return 0;
}
