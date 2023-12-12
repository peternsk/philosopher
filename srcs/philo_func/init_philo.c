/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:45:53 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/12 13:25:25 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    typedef struct s_philo
    {
    	int				id;
    	int				is_dead;
    	pthread_t		platon;
    	pthread_mutex_t	r_fork;
    	pthread_mutex_t	*l_fork;
    	struct s_global	*gld_s;
    }					t_philo;
*/

#include "../../philo.h"

t_philo    *init_philo(t_global *glb_s)
{
    t_philo *platon;
    
    platon = (t_philo *)malloc(1 * sizeof(t_philo));
    if (!platon)
        return(NULL);
    platon->id = 0;
    platon->plates = glb_s->must_eat;
    platon->l_fork
    
}