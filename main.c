/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:23:44 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/12 15:23:10 by cfiliber         ###   ########.fr       */
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
		{
			free(data.philos_array);
			return (-1);
		}
		data.start_time = ft_get_time();
		if (create_threads(&data, data.philos_array) != 0)
		{
			end(&data, data.philos_array);
			return (-1);
		}
		end(&data, data.philos_array);
	}
	return (0);
}
