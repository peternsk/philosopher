#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BIG 1000000000UL
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void	*count_to_big(void *arg)
{
	(void)arg;
	for(int32_t i = 0; i < BIG; i++)
	{
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return(NULL);
}

int		main()
{
	pthread_t thread;
	pthread_create(&thread, NULL, &count_to_big, NULL);
	//count_to_big();
	count_to_big(NULL);
	pthread_join(thread, NULL);
	printf(" Done counter = %u\n", counter);
}