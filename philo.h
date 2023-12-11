/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:10 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/08 23:24:05 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				is_dead;
    pthread_t       platon;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_global
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
    pthread_mutex_t g_mutex;
    t_philo         *asso_philo;
    
}					t_global;

/* parsing */
bool				check_dig_arg(char *str);
bool				check_sign_arg(char *str);
bool				parser(int ac, char **av);
int					ft_atoi(char *str);

/* philo_functions */
void	set_philo(t_global *g_struct);

#endif