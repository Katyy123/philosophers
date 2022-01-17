/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:09:53 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/17 20:07:59 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_mutex_unlock(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->philos_nb)
	{
		pthread_mutex_unlock(&data->phil_arr[j].right_fork);
		j++;
	}
}

void	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->death_meal);
	if ((ft_get_time() - data->phil_arr[i].last_meal_time) >= data->time_die)
	{
		if (data->dead_philo == FALSE && data->all_ate == FALSE)
		{
			print_status(data, data->phil_arr[i].id, DIE);
			data->dead_philo = TRUE;
		}
		fork_mutex_unlock(data);
	}
	pthread_mutex_unlock(&data->death_meal);
	usleep(1000);
}

void	*death_check(void *void_philo)
{
	t_data	*data;
	t_philo	*philo;
	int		i;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	while (data->dead_philo == FALSE && data->all_ate == FALSE)
	{
		i = 0;
		while (i < data->philos_nb && data->dead_philo == FALSE
			&& data->all_ate == FALSE)
		{
			is_dead(data, i);
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
	if(pthread_create(&philo->death_th_id, NULL, death_check, philo) != 0)
		return(error_th_null("death th create failed", philo->id, data));
	if (philo->id % 2 != 0)
		ft_sleep(data->time_eat / 10, data);
	while (data->dead_philo == FALSE)
	{
		activity(philo, data);
		pthread_detach(philo->death_th_id);
		if (data->all_ate == TRUE)
			return (NULL);
	}
	return (NULL);
}

int	create_threads(t_data *data, t_philo *ph_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		if (pthread_create(&ph_arr[i].thread_id, NULL, thread, &ph_arr[i]))
			return (error_thread("pth_create failed", ph_arr[i].id, data));
		ph_arr[i].last_meal_time = ft_get_time();
		i++;
	}
	return (1);
}