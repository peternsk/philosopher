/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:03:27 by pnsaka            #+#    #+#             */
/*   Updated: 2023/11/27 11:11:23 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_messaage( void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("%s\n", message);
}

int main(void)
{
    
}


