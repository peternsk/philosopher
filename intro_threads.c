/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:08:06 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/04 09:35:48 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mails = 0;
pthread_mutex_t mutex;

void    *routine()
{
    for(int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        //check assambly code
        pthread_mutex_unlock(&mutex);
    }
    return(NULL);
}

int     main(int ac, char **av)
{
    (void)ac;
    int num_of_th = atoi(av[1]);
    
    pthread_t th[num_of_th];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < num_of_th; i++)
    {
        if(pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            printf("Failed to create threads!\n");
            return (1);
        }
        printf("philo %d has started\n", i);
    }
    for(int i = 0; i < num_of_th; i++)
    {
        if(pthread_join(th[i], NULL) != 0)
        {
            printf("Failed to join threads!\n");
            return (5);
        }
        printf("philo %d has finish execution\n", i);
    }
    printf("Number of mails : %d\n", mails);
    pthread_mutex_destroy(&mutex);
    return(0);
}