/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:58:50 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/21 16:21:48 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, int *is_toobig)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (((2147483647 - (str[i] - 48)) / 10 < num))
			*is_toobig = TRUE;
		else
			*is_toobig = FALSE;
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int	ft_isdigit(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		flag = 1;
		i++;
	}
	if (str[i] == '\0' && flag == 1)
		return (1);
	else
		return (0);
}
