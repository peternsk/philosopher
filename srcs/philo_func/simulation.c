/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:59:10 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/08 14:15:39 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static	void	count_plate(t_philo *philo) // a travailler
{
	pthread_mutex_lock(&philo->action->mtx_plate);
	if(philo->glb_s->must_eat > 0 && philo->glb_s->plate_counter == true)
	{
		if(philo->plates != philo->glb_s->must_eat)
		{
			philo->plates++;
			printf("philo ID %d num of plate %d\n",philo->id, philo->plates);
		}
		else
			philo->is_full = true;
	}
	pthread_mutex_unlock(&philo->action->mtx_plate);
}

void	eat_func(t_philo *philo) // a travailler
{
	pthread_mutex_lock(&philo->l_fork->fork);
	print_statement(philo, L_FORK);
	pthread_mutex_lock(&philo->r_fork->fork);
	print_statement(philo, R_FORK);
	//eating 
	pthread_mutex_lock(&philo->action->eating);
	usleep(philo->glb_s->time_to_eat);
	printf("philo %d %s\n", philo->id, EAT);
	count_plate(philo);
	pthread_mutex_unlock(&philo->action->eating);
	
	//unlock
	pthread_mutex_unlock(&philo->l_fork->fork);
	print_statement(philo, RL_FORK);
	pthread_mutex_unlock(&philo->r_fork->fork);
	print_statement(philo, RR_FORK);
}

void	pause_func(t_philo *philo) // a travailler
{
	printf("philo %d %s\n", philo->id, THINKING);
	usleep(philo->glb_s->time_to_eat * 2);
}

void	*simulation(void *arg) // a travailler
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(1)
	{
		eat_func(philo);
		pause_func(philo);
	}
	return(0);
}
void    *start_thread(t_global *glb_s) // a travailler
{
    int i;

    i = -1;
    while(++i < glb_s->n_of_p)
        if(pthread_create(&glb_s->asso_philo[i].platon, NULL, &simulation, &glb_s->asso_philo[i]) != 0)
            ext_err("thread create error..");
    i = -1;
    while(++i < glb_s->n_of_p)
        if(pthread_join(glb_s->asso_philo[i].platon, NULL) != 0)
            ext_err("thread join error..");
	return(0);
}

