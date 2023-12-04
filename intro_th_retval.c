/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_th_retval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:39:26 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/04 10:04:06 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *roll_dice(void * arg)
{
    (void)arg;
    int value = (rand() % 100) + 1;
    printf("Value %d", value);
    return(NULL);
}

int     main(int ac, char **av)
{
    (void)ac;
    (void)av;
    srand(time(NULL));
    pthread_t th1, th2;
    if(pthread_create(&th1, NULL, &roll_dice, NULL) != 0)
        return(1);
    if(pthread_join(th1, NULL) != 0)
        return(2);
    return(0);
}