/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:35:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/20 19:24:30 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	parsing(int argc)
{
	int	i;
	//int num;
	int	*is_toobig;
	
	i = 1;
	while (i <= argc)
	{
		//if (!(ft_isdigit(argv[i])))
			//return (error("one or more arguments may not be int"));
		is_toobig = malloc(sizeof(int) * 2);
		is_toobig[1] = 0;
		//num = ft_atoi(argv[i], is_toobig);
		//if (num == 0)
			//return (error("0 is not an allowed argument"));
		//if (*is_toobig == TRUE)
			//return (error("arguments are too big"));
		free(is_toobig);
		//set_data_struct(num, data, i);
		i++;
	}
	return (1);
}
