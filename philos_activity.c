/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_activity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:16:48 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/18 16:06:13 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_ate_check(t_data *data)
{
	if (data->nb_philos_ate == data->philos_nb)
		data->all_ate = TRUE;
}

void	ft_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->right_fork);
	if (data->all_ate == FALSE && data->dead_philo == FALSE)
		print_status(data, philo->id, FORK);
	pthread_mutex_lock(philo->left_fork);
	if (data->all_ate == FALSE && data->dead_philo == FALSE)
		print_status(data, philo->id, FORK);
	pthread_mutex_lock(&data->death_meal);
	if (data->all_ate == FALSE && data->dead_philo == FALSE)
	{
		print_status(data, philo->id, EAT);
		philo->last_meal_time = ft_get_time();
	}
	pthread_mutex_unlock(&data->death_meal);
	ft_sleep(data->time_eat, data);
	philo->meals_nb++;
	if (philo->meals_nb == data->times_must_eat)
	{
		philo->finish = TRUE;
		data->nb_philos_ate++;
	}
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	activity(t_philo *philo, t_data *data)
{
	if (data->dead_philo == FALSE && data->all_ate == FALSE)
	{	
		if (philo->finish == FALSE)
			ft_eat(philo);
		all_ate_check(data);
		if (data->all_ate == FALSE && data->dead_philo == FALSE)
		{
			print_status(data, philo->id, SLEEP);
			ft_sleep(data->time_sleep, data);
		}
		if (data->dead_philo == FALSE && data->all_ate == FALSE)
			print_status(data, philo->id, THINK);
	}
	return (1);
}
