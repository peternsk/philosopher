/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:35:07 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/11 09:50:23 by pnsaka           ###   ########.fr       */
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
    #   #          #   #   #          #   #   #          #   #   #          #   #   #          #   #
    #   #          #   #   #          #   #   #          #   #   #          #   #   #          #   # 
    #   ############   #   ############   #   ############   #   ############   #   ############   #
    #                  #                  #                  #                  #                  #
    ################################################################################################

    --> Malloc the array of struc with the number of philo that i want.
    
*/

#include "../../philo.h"

t_philo	*create_philo(t_global *glb_s)
{
	int	i;

	i = 0;
	glb_s->asso_philo = (t_philo *)malloc(glb_s->n_of_p * sizeof(t_philo) + 1);
	if (!glb_s->asso_philo)
		return (0);
	while (&glb_s->asso_philo)
	{
		glb_s->asso_philo[i].id = i;
		i++;
	}
	return (glb_s->asso_philo);
}
