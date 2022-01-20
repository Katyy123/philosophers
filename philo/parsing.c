/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:35:30 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/18 16:04:06 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_toobig(int *is_toobig)
{
	if (*is_toobig == TRUE)
	{
		free(is_toobig);
		return (1);
	}
	return (0);
}

int	check_num(int num, int *is_toobig)
{
	if (num == 0)
	{
		free(is_toobig);
		return (error("0 is not an allowed argument"));
	}
	if (ft_is_toobig(is_toobig) == 1)
		return (error("one or more arguments are too big"));
	free(is_toobig);
	return (1);
}

int	parsing(int argc, char **argv, t_data *data)
{
	int	i;
	int	num;
	int	*is_toobig;

	i = 1;
	while (i < argc)
	{
		if (!(ft_isdigit(argv[i])))
			return (error("one or more arguments may not be int"));
		is_toobig = malloc(sizeof(int) * 1);
		if (!is_toobig)
			return (error("is_toobig malloc failed"));
		num = ft_atoi(argv[i], is_toobig);
		if (!check_num(num, is_toobig))
			return (0);
		set_data_1(num, data, i);
		i++;
	}
	return (1);
}
