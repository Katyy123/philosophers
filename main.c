/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:23:44 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/22 13:06:04 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data 	data;
	
	if (argc != 5 && argc != 6)
		return (error("invalid number of arguments"));
	else
	{
		if (!parsing(argc, argv, &data))
			return(-1);
		if (!init(&data))
			return (-1);
	}
	return (0);
}
