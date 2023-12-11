/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:44 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/11 08:33:44 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    this fonction will take the verify if the philo have the two 
    fork require to eat(print)

    -> mutex_lock(philo)
       timestamp_in_ms X has taken right fork
    -> mutex_lock(philo - 1)
       timestamp_in_ms X has taken left fork

        mutex_lock()
            printf(philo.id is eating);
        mutex_lock()
    
    -> mutex_unlock(philo)
    -> mutex_unlock(philo - 1)
*/

#include "../../philo.h"

void	*eat(void *arg)
{
	t_global *g_struct;

	g_struct = (t_global *)arg;
	return (NULL);
}
