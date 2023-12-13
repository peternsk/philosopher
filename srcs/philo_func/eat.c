/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:44 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/13 13:26:40 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    this fonction will take the verify if the philo have the two 
    fork require to eat(print)
    --> impaire(fork);
    --> else think
    
    -> mutex_lock(mutex r)
       timestamp_in_ms X has taken right fork
    -> mutex_lock(mutex l)
       timestamp_in_ms X has taken left fork

       func ---->evaluation du temps (think + sleep) < time_to_die

        mutex_lock(gls-> mutex_eat)
            printf(philo.id is eating);
            usleep(glb_s->time_to_eat)
        mutex_unlock()
    
    -> mutex_unlock(philo)
    -> mutex_unlock(philo - 1)
*/

#include "../../philo.h"

void	*eat(void *arg)
{
	t_global	*g_struct;

	g_struct = (t_global *)arg;
	return (NULL);
    
}
