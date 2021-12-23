/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:09:53 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/23 18:46:27 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *void_philo)
{
	t_data *data;
	t_philo *philo;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->)
		
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