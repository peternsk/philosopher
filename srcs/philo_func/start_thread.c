/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:03:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/07 23:58:39 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void    start_thread(t_global *glb_s)
{
    int i;

    i = 0;
    while(&glb_s->asso_philo[i] != '\0')
    {
        if(pthread_create(&glb_s->asso_philo[i], NULL, eat, &glb_s->asso_philo[i]) != 0)
            return(0);
        i++;
    }
    i = 0;
    while(&glb_s->asso_philo[i] != '\0')
    {
        if(pthread_join(&glb_s->asso_philo[i], NULL) != 0)
            return(0);
        i++;
    }
}