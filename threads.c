/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:09:53 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/05 19:04:28 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	t_data	*data;
	data = philo->data;
	pthread_mutex_lock(&philo->right_fork);
	ft_print(data, philo->id, FORK);
	pthread_mutex_lock(philo->left_fork);
	ft_print(data, philo->id, FORK);
	//confronta last_meal_time con time_die;
	
}

void	*thread(void *void_philo)
{
	t_data *data;
	t_philo *philo;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	if (philo->id % 2 != 0)
		ft_usleep(data->time_eat / 10);
	while (!data->dead_philo)
	{
		eat(philo);
	}	
}

int	create_threads(t_data *data, t_philo *phil_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		if (pthread_create(&phil_arr[i].thread_id, NULL, thread, &phil_arr[i]) != 0)
			return (error_thread("pthread_create failed", phil_arr[i].id));
		i++;
		phil_arr[i].last_meal_time = ft_get_time();
	}
	return (1);
}