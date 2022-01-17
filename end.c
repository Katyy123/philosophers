/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:06:09 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/17 20:10:42 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexes(t_data *data, t_philo *philo_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		if (pthread_mutex_destroy(&philo_arr[i].right_fork) != 0)
		{
			error_thread("fork mut_destroy failed", philo_arr[i].id, data);
			break;
		}
		i++;
	}
	if (pthread_mutex_destroy(&data->death_meal) != 0)
		error("death mutex destroy failed");
	if (pthread_mutex_destroy(&data->print) != 0)
		error("print mutex destroy failed");
	return (1);
}

int	end(t_data *data, t_philo *phil_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		pthread_join(phil_arr[i].thread_id, NULL);
		i++;
	}
	if (data->all_ate == TRUE && data->dead_philo == FALSE)
	{
			i = 0;
			while (i < data->philos_nb)
			{
				printf("Philo %d have eaten %d times\n",
					phil_arr[i].id + 1, phil_arr[i].meals_nb);
				i++;
			}
	}
	destroy_mutexes(data, phil_arr);
	free(phil_arr);
	return (1);
}
