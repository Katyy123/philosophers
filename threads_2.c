/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:36:29 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/11 19:37:52 by cfiliber         ###   ########.fr       */
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
