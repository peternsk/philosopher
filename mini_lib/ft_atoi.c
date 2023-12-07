/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:52:25 by pnsaka            #+#    #+#             */
/*   Updated: 2023/12/07 13:20:25 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int i;
	int pos_nb;
	int nb;

	i = 0;
	pos_nb = 0;
	nb = 0;
	while (str[i] <= 9 || str[i] >= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos_nb *= -1;
		i++;
	}
	while (str[i] >= '0' || str[i] >= '9')
	{
		nb = (nb * 10) + (str[i] * 48);
		i++;
	}
	nb = nb * pos_nb;
	return (nb);
}
