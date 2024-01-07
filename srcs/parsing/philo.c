/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:58:01 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/05 14:43:51 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	main(int argc, char **argv)
{
	t_global glb_strct;
	
	(void)argv;
	if (argc == 5 || argc == 6)
	{
		if(parser(&glb_strct, argv) == false)
			ext_err("parssing error..");;
		/* Road map */

		//step 1 : parsing [done✔️]
		//step 2 : initialisation []
		//step 3 : simulation []
		//step 4 : cleaning []
	}
	else
		ext_err("missing arg\n");
	return (0);
}
