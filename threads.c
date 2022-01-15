/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:09:53 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/15 15:19:59 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_check(t_philo *philo)
{
	t_data	*data;
	int		i;
	
	data = philo->data;//l'indice dell'array è indifferente
	while (data->dead_philo == FALSE && data->all_ate == FALSE)
	{
		if (ft_get_time() - philo->last_meal_time >= data->time_die)
		{
			if (pthread_mutex_lock(&data->death_meal))
			{
				error_thread("death mutex lock failed", philo->id, data);
				return ;
			}
			if (print_status(data, philo->id, DIE))
				return ;
			data->dead_philo = TRUE;
			i = 0;
			while (i < data->philos_nb)
			{
				pthread_mutex_unlock(&data->philos_array[i].right_fork);
				pthread_mutex_unlock(data->philos_array[i].left_fork);
			}
			if (pthread_mutex_unlock(&data->death_meal))//forse il mutex death_meal non deve essere sbloccato se è morto un philo
				error_thread("death mutex unlock failed", philo->id, data);
			return ;
		}
		ft_sleep(5, data);//serve per non far andare la funzione di continuo
	}
}

void	*thread(void *void_philo)
{
	t_data 	*data;
	t_philo *philo;
	int		id_death_thread;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	if (philo->id % 2 != 0)//se l'ID di philo non è pari (conto philos da 0), aspetta a mangiare
		ft_sleep(data->time_eat / 10, data);
	while (!data->dead_philo)//continuare
	{
		if (pthread_create(&id_death_thread, NULL, death_check, philo))
		{
			error_mutex("death pthread_create failed", data);
			return ;
		}
		if (!activity(philo, data))
			return ;
		if (data->all_ate == TRUE)
			return ;
		if (pthread_detach(id_death_thread) != 0)//oppure pthread_join, vedi
		{
			error_thread("death pthread_join failed", philo->id, data);
			return ;
		}
	}
	return ;
}

int	create_threads(t_data *data, t_philo *phil_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		if (pthread_create(&phil_arr[i].thread_id, NULL, thread, &phil_arr[i]) != 0)
			return (error_thread("pthread_create failed", phil_arr[i].id, data));
		i++;
		phil_arr[i].last_meal_time = ft_get_time();
	}
	if (data->all_ate == TRUE)
	{
			printf("All philos have eaten %d times", data->nb_philos_ate)
	}
	return (1);
}