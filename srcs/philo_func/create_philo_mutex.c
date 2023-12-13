/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:35:07 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/13 13:05:38 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
        arr_philo[0]       arr_philo[1]       arr_philo[2]       arr_philo[3]       arr_philo[4]    
    ################################################################################################
    #      struc       #      struc       #      struc       #      struc       #       struc      #
    #   ############   #   ############   #   ############   #   ############   #   ############   #
    #   #   ID     #   #   #          #   #   #          #   #   #          #   #   #          #   #
    #   #   l_fork #   #   #          #   #   #          #   #   #          #   #   #          #   #
    #   #   r_fork #   #   #          #   #   #          #   #   #          #   #   #          #   #
    #   ############   #   ############   #   ############   #   ############   #   ############   #
    #                  #                  #                  #                  #                  #
    ################################################################################################

    --> Malloc the array of struc with the number of philo that i want.
    
*/

#include "../../philo.h"

t_philo	*create_philo_mutex(t_global *glb_s)
{
	int	i;

	i = 0;
	glb_s->asso_philo = (t_philo *)malloc(glb_s->n_of_p * sizeof(t_philo) + 1);
	if (!glb_s->asso_philo)
		return (0);
	while (glb_s->asso_philo)
	{
		if (pthread_mutex_init(&glb_s->asso_philo[i].r_fork, NULL) != 0)
			return (0);
	}
    i = -1;
    while(&glb_s->asso_philo[++i] != 0)
    {
        if (i == 0)
            glb_s->asso_philo[i].l_fork = &glb_s->asso_philo[glb_s->n_of_p].r_fork;
        glb_s->asso_philo[i].l_fork = &glb_s->asso_philo[i -1].r_fork;
    }
	return (glb_s->asso_philo);
}
