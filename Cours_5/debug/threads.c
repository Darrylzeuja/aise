#include <stdio.h>
#include <pthread.h>
#define error(...) do{ fprintf(stderr, __VA_ARGS__); } while(0)

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * func(void * arg)
{
	int * id = (int*)arg;
	if(!id)
		error("id is NULL !!");


	pthread_mutex_lock(&lock);
	fprintf(stderr, "I'm %d\n", *id);
	if(*id)
	{
		pthread_mutex_lock(&lock);
	}

	return NULL;
	
}

#ifndef MAX
#define MAX 4
#endif /* ifndef MAX */
int main(int argc, char *argv[])
{
	pthread_t t[MAX];
	int i;

	for (i = 0; i < MAX; ++i) {
		pthread_create(t + i, NULL, func, &i);
	}

	for (i = 0; i < MAX; ++i) {
		pthread_join(*(t+i), NULL);
	}
	return 0;
}
