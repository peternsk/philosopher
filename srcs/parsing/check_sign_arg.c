/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sign_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:23:11 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/08 14:47:56 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool    check_sign_arg(char *str)
{
    int i;
    int sign_count;

    i = 0;
    sign_count = 0;
    if(!str)
        return(false);
    if(str[i] == '-' || str[i] == '+')
    {
        sign_count++;
        i++;
    }
    while(str[i] != '\0')
    {
        if(str[i] == '-' || str[i] == '+')
            return(false);
        i++;
    }
    if(sign_count > 1)
        return(false);
    return(true);
}
