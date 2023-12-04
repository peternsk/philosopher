/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intor_th_retval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:39:26 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/04 10:40:21 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *roll_dice(void * arg)
{
    (void)arg;
    int value = (rand() % 100) + 1;
    int *result = malloc(sizeof(int));
    if(!result)
        return(0);
    *result = value;
    // printf("Value %d\n", value);
    return((void *)result);
}

int     main(int ac, char **av)
{
    (void)ac;
    int noft = atoi(av[1]);
    int *res;
    srand(time(NULL));
    pthread_t th[noft];
    
    for(int i = 0; i < noft; i++)
    {
        if(pthread_create(&th[i], NULL, &roll_dice, NULL) != 0)
            return(1);
        printf("rand %d has started\n", i);
    }
    for(int i = 0; i < noft; i++)
    {
        if(pthread_join(th[i], (void **) &res) != 0)
            return(4);
        printf("Result: %d\n", *res);
    }
    free(res);
    return(0);
}