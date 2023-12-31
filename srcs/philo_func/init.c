/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:45:53 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/08 13:51:20 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void		*clean_malloc(size_t space_nd)
{
	void	*ret_val;
	ret_val = malloc(space_nd);
	if(ret_val == NULL)
		ext_err("malloc err..");
	return(ret_val);
}

static void		init_arr_mutx(t_philo *philo, t_fork *fork, int position)
{
	if(philo->id % 2 == 0)
	{
		philo->r_fork = &fork[position];
		philo->l_fork = &fork[(position + 1) % philo->glb_s->n_of_p];
	}
	philo->r_fork = &fork[(position + 1) % philo->glb_s->n_of_p];
	philo->l_fork = &fork[position];
	printf("platon right fork  %d\n", philo->r_fork->id);
	printf("platon left fork  %d\n", philo->l_fork->id);

}
static void		init_act_mtx(t_philo *philo)
{
	philo->action = clean_malloc(sizeof(t_mtx_act) * 1);
	if (pthread_mutex_init(&philo->action->eating, NULL) != 0)
			return ;
	if (pthread_mutex_init(&philo->action->sleeping, NULL) != 0)
			return ;
	if (pthread_mutex_init(&philo->action->writing, NULL) != 0)
			return ;
	printf("all the action mutex have been initiated\n");
}

static void 	init_philo(t_global *glb_s)
{
    t_philo *platon;
    
	int i;

	i = -1;
	while(++i < glb_s->n_of_p)
	{
		platon = glb_s->asso_philo + i;
		platon->id = i + 1;
		printf("platon ID  %d\n", platon->id);
		platon->is_dead = false;
		platon->is_full = false;
		platon->plates 	= 0;
		platon->glb_s = glb_s;
		init_arr_mutx(platon, glb_s->forks, i + 1);
		init_act_mtx(platon);
	}
}

void init_val(t_global *glb_s, char **val)
{
	int i;

	i = -1;
	glb_s->n_of_p        = ft_atol(val[1]);
	glb_s->time_to_die   = ft_atol(val[2]) * 1000;
	glb_s->time_to_eat   = ft_atol(val[3]) * 1000;
	glb_s->time_to_sleep = ft_atol(val[4]) * 1000;
    if(val[5])
	{
	    glb_s->must_eat  = ft_atol(val[5]);
		glb_s->plate_counter = true;
	}
	else
	{
		glb_s->must_eat  = -1 ;
		glb_s->plate_counter = false;
	}
	glb_s->asso_philo = clean_malloc(sizeof(t_philo) * (glb_s->n_of_p));
	glb_s->forks = clean_malloc(sizeof(t_fork) * (glb_s->n_of_p));
	while(++i < glb_s->n_of_p)
	{
		if (pthread_mutex_init(&glb_s->forks[i].fork, NULL) != 0)
			return ;
		glb_s->forks[i].id = i;
	}
	init_philo(glb_s);
}

