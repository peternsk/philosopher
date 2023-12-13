/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_glb_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:41 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/13 12:12:26 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_global	*init_glb_s(char **av)
{
	t_global	*glb_s;

	glb_s = (t_global *)malloc(1 * sizeof(t_global));
	if (!glb_s)
		return (0);
	glb_s->n_of_p        = ft_atoi(av[1]);
	glb_s->time_to_die   = ft_atoi(av[2]);
	glb_s->time_to_eat   = ft_atoi(av[3]);
	glb_s->time_to_sleep = ft_atoi(av[4]);
    if(av[5])
	    glb_s->must_eat  = ft_atoi(av[5]);
}
