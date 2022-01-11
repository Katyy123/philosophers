/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:23:44 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/11 20:00:23 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexes()
{
	
}

int	end(t_data *data, t_philo *philos_arr)
{
	int	i;
	
	if (pthread_join(data->id_death_thread, NULL) != 0)
		return (error("death pthread_join failed"));
	i = 0;
	while (i < data->philos_nb)
	{
		if (pthread_join(philos_arr[i].thread_id, NULL) != 0)
			return (error_thread("pthread_join failed", philos_arr[i].id));
		i++;
	}
	//chiama mutex_destroy per ogni mutex
	return (1);
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
		if (!create_threads(&data, data.philos_array))
			return (-1);
		if (!end(&data, data.philos_array))
			return (-1);
	}
	return (0);
}
