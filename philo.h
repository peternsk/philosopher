/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:10 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/13 12:13:07 by pnsaka           ###   ########.fr       */
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
	int				plates;
	pthread_t		platon;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	struct s_global	*gld_s;
}					t_philo;

typedef struct s_global
{
	int				n_of_p;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	g_mutex;
	t_philo			*asso_philo;

}					t_global;

/* parsing */
bool				check_dig_arg(char *str);
bool				check_sign_arg(char *str);
bool				parser(int ac, char **av);
int					ft_atoi(char *str);

/*-- philo_func --*/
t_philo				*create_philo(t_global *glb_s);
t_global			*init_glb_s(char **av);
t_philo    			*init_philo(t_global *glb_s);


#endif