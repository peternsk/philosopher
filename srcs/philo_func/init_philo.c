/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:45:53 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/13 13:08:01 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_philo    *init_philo(t_global *glb_s)
{
    t_philo *platon;
    
    platon = (t_philo *)malloc(1 * sizeof(t_philo));
    if (!platon)
        return(NULL);
    platon->id = 0;
    platon->plates = glb_s->must_eat;
}