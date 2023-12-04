/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intor_th_retval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:39:26 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/04 09:49:01 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *roll_dice(void * arg)
{
    (void)arg;
    int value = (rand() % 6) + 1;
    printf("Value %d", value);
    return(NULL);
}

int     main(int ac, char **av)
{
    (void)ac;
    (void)av;
    srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th, NULL, &roll_dice, NULL) != 0)
        return(1);
    if(pthread_join(th, NULL) != 0)
        return(2);
    return(0);
}