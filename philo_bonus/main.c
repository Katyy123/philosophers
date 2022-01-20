/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:32:51 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:04:33 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (error("invalid number of arguments"));
	else
	{
		if (!parsing(argc, argv, &data))
			return (-1);
		if (!init(&data))
		{
			free(data.phil_arr);
			return (-1);
		}
		if (!create_processes(&data, data.phil_arr))
		{
			end(&data, data.phil_arr);
			return (-1);
		}
		end(&data, data.phil_arr);
	}
	return (0);
}
