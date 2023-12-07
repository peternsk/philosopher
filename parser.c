/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:56:44 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/07 15:05:38 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    parcer(int ac, char **av)
{
    int i;

    i = 0;
    while(i < ac)
    {
        if(check_dig_arg(av[i]) == false)
            return(false);
        if(check_dig_arg(av[i]) == false)
            return(false);
        i++;
    }
    return(true);
}
