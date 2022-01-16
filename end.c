/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:06:09 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/16 17:45:05 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexes(t_data *data, t_philo *philo_arr)//controlla che tutti i mutex siano unlocked
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
		//if (pthread_mutex_destroy(&philo_arr[i].eating) != 0)
		//{
			//error_thread("eating mut_destroy failed", philo_arr[i].id, data);
			//break;
		//}
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
	//pthread_detach(data->death_thread_id);//oppure pthread_join, vedi
	//{
		//error_mutex("death pthread_join failed", data);
		//return (0);
	//}
	//if (data->all_ate || data->dead_philo)
	//{
		//exit (1);
	//}
	while (i < data->philos_nb)
	{
		pthread_join(phil_arr[i].thread_id, NULL);
		//{
			//error_thread("pthread_join failed", philos_arr[i].id, data);//non appena un join non funziona, ritorna.
			//break;                                               //Va bene così perchè fa join dei philos nello stesso ordine con cui fa pthread_create
		//}
		i++;
	}
	if (data->all_ate == TRUE && data->dead_philo == FALSE)
	{
			//i = 0;
			//while (i < data->philos_nb)
			//{
				//printf("Philo %d have eaten %d times\n", phil_arr[i].id + 1, phil_arr[i].meals_nb);
				//i++;
			//}
			printf("All philos have eaten %d times\n", data->times_must_eat);
	}
	destroy_mutexes(data, phil_arr);//chiama mutex_destroy per ogni mutex
	free(phil_arr);
	return (1);
}
