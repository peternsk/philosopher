/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:58:01 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/08 09:11:25 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     main(int argc, char **argv)
{
    if(argc == 5 || argc == 6)
    {
        if(argc == 5)
        {
            if(parcer(argc, argv) == false)
                return (0);
            else
                printf("all good\n");
        }
        if(argc == 6)
        {
            if(parcer(argc, argv) == false)
                return (0);
            else
                printf("all good\n");
        }
    }
    printf("missing arg\n");
}