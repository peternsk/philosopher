#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*my_turn(void *arg)
{
	(void)arg;
	int *iptr = (int*)malloc(sizeof(int));
	if(!iptr)
		return(NULL);
	*iptr = 5;
	for(int i = 0; i < 8; i++)
	{
		sleep(3);
		printf("my turn! %d %d\n", i, *iptr);
		(*iptr)++;
	}
	return(iptr);
}

void	*your_turn(void *arg)
{
	(void)arg;
	for(int i = 0; i < 3; i++)
	{
		sleep(1);
		printf("your turn %d\n", i);
	}
	return(NULL);
}

int		main()
{
	pthread_t newthread;
	pthread_t newer_thread;
	int *result;

	pthread_create(&newthread, NULL, &my_turn, NULL);
	pthread_create(&newer_thread, NULL, &your_turn, NULL);
	//my_turn();
	//your_turn();
	pthread_join(newthread, (void *)&result);
	pthread_join(newer_thread, NULL);
	//pthread_detach(newer_thread);

	printf("thread's done : result = %d\n", *result);
}
