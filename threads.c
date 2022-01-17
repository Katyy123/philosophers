/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:09:53 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/17 17:47:18 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_check(void *void_philo)
{
	t_data	*data;
	t_philo	*philo;
	int		i;
	int		j;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	while (data->dead_philo == FALSE && data->all_ate == FALSE)
	{
		i = 0;
		while (i < data->philos_nb && data->dead_philo == FALSE && data->all_ate == FALSE)
		{
			pthread_mutex_lock(&data->death_meal);
			if ((ft_get_time() - data->philos_array[i].last_meal_time) >= data->time_die)
			{
				if (data->dead_philo == FALSE && data->all_ate == FALSE)
				{
					print_status(data, data->philos_array[i].id, DIE);
					data->dead_philo = TRUE;
					data->philos_array[i].is_dead = TRUE;
				}
				j = 0;
				//pthread_mutex_unlock(&data->death_meal);
				//pthread_mutex_unlock(&philo->right_fork);
				while (j < data->philos_nb)
				{
					pthread_mutex_unlock(&data->philos_array[j].right_fork);
					j++;
				}
			}
			pthread_mutex_unlock(&data->death_meal);
			usleep(1000);//, data);//serve per non far andare la funzione di continuo
			i++;
		}
	}
	return (NULL);
}

void	*thread(void *void_philo)
{
	t_data 	*data;
	t_philo *philo;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	if(pthread_create(&philo->death_thread_id, NULL, death_check, philo) != 0)
		return(error_thread_null("death thread create failed", philo->id, data));
	if (philo->id % 2 != 0)//se l'ID di philo non è pari (conto philos da 0), aspetta a mangiare
		ft_sleep(data->time_eat / 10, data);
	while (data->dead_philo == FALSE)//continuare
	{
		//pthread_create(&philo->death_thread_id, NULL, death_check, philo);
		activity(philo, data);
		pthread_detach(philo->death_thread_id);
		//if (philo->is_dead == TRUE)
		//{
			//print_status(data, philo->id, DIE);
			//return (NULL);
		//}
		if (data->all_ate == TRUE)
			return (NULL);
		//pthread_detach(philo->death_thread_id);//oppure pthread_join, vedi
	}
	return (NULL);
}

int	create_threads(t_data *data, t_philo *phil_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		if (pthread_create(&phil_arr[i].thread_id, NULL, thread, &phil_arr[i]) != 0)
			return (error_thread("pthread_create failed", phil_arr[i].id, data));
		phil_arr[i].last_meal_time = ft_get_time();
		i++;
	}
	//pthread_create(&data->death_thread_id, NULL, death_check, data->philos_array)
	return (1);
}