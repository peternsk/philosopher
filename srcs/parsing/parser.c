/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:56:44 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/08 14:54:08 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool    parser(int ac, char **av)
{
    int i;

    i = 0;
    while(i < ac)
    {
        if(check_dig_arg(av[i]) == false)
            return(false);
        if(check_sign_arg(av[i]) == false)
            return(false);
        i++;
    }
    return(true);
}
