/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dig_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:43:40 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/05 18:50:28 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool    check_dig_arg(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
		while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
        if((str[i] >= '0' && str[i] <= '9') || (str[i] == '+'))
        	i++;
		else
        	return(false);
    }
    return(true);
}
