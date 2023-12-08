/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:10 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/08 11:16:03 by pnsaka           ###   ########.fr       */
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
	pthread_mutex_t	fork;
}					t_philo;

typedef struct s_global
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
    pthread_mutex_t g_mutex;
    t_philo         *asso_philo;
    
}					t_global;

bool				check_dig_arg(char *str);
bool				check_sign_arg(char *str);
bool				parcer(int ac, char **av);
int					ft_atoi(char *str);

#endif