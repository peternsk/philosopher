/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:56:44 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/05 14:54:38 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool	parser(t_global *glb_s, char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (check_dig_arg(av[i]) == false)
			return (false);
		if (check_sign_arg(av[i]) == false)
			return (false);
		i++;
	}
	glb_s->n_of_p        = ft_atol(av[1]) * 1000;
	glb_s->time_to_die   = ft_atol(av[2]) * 1000;
	glb_s->time_to_eat   = ft_atol(av[3]) * 1000;
	glb_s->time_to_sleep = ft_atol(av[4]) * 1000;
    if(av[5])
	    glb_s->must_eat  = ft_atol(av[5]);
	else
		glb_s->must_eat  = -1 ;
	return (true);
}
