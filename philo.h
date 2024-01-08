/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:10 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/07 21:26:45 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define EAT	"philo is eating"
# define SLEEP	"philo is sleeping"
# define L_FORK "philo has the left fork"
# define R_FORK "philo has the left fork"
# define FULL	"philo is full"
# define DEAD	"philo is dead"

typedef struct s_fork
{
	pthread_mutex_t fork;
	int				id;
}			t_fork;

typedef struct s_philo
{
	int				id;				// rank of the philo in the array
	bool			is_dead; 		// flag that will be raised if philo is dead
	bool			is_full;		// flag that will be raised if philo is full
	int				plates;			// number of plates philo has eaten
	long			lte;			// last time eat
	pthread_t		platon;			// the philo
	t_fork			*r_fork;		// the fork the philo
	t_fork			*l_fork;		// a pointer to the fork of the philo beside
	struct s_global	*glb_s;			// a pointer to the global structure for philo to have asses
}					t_philo;

typedef struct s_global
{
	int				n_of_p;			// total number of philo
	long			time_to_die;	// limit time to die
	long			time_to_eat;	// limit time to eat
	long			time_to_sleep;	// time that philo si sleeping
	int				must_eat;		// number of plate the philo must eat
	long			strt_sim_time;	// time at the beginning of the simulation
	pthread_mutex_t	eat;			// the mutex that will be lock or unlock by philo when eating
	pthread_mutex_t	sleep;			// the mutex that will be lock or unlock by philo when sleeping
	t_fork			*forks;			// an array of all the forks
	t_philo			*asso_philo;	// an array of all the philos

}					t_global;

/* parsing */
bool				check_dig_arg(char *str);
bool				check_sign_arg(char *str);
bool				parser(/*t_global *glb_s,*/ char **av);

/*-- philo_func --*/
void 				init_val(t_global *glb_s, char **val);
void			    start_thread(t_global *glb_s);

/*-- utils --*/
long				ft_atol(char *str);
void				ext_err(char *err_str);

#endif