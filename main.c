/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:23:44 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/22 19:29:25 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

create_threads(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		pthread_create();
		i++;
	}
}

long long	ft_get_time(void)
{
	struct timeval	t;
	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1e3) + (t.tv_usec * 1e-3));
}

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
		data.start_time = ft_get_time();
		create_threads(&data);
	}
	return (0);
}
