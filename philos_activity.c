/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_activity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:16:48 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/13 19:47:03 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_ate_check(t_data *data, t_philo *phil_arr)
{
	int	i;

	i = 0;
	while (i < data->philos_nb)
	{
		if (phil_arr[i].finish == FALSE)
		{
			data->all_ate = FALSE;
			break ;
		}
		else
			data->all_ate = TRUE;
		i++;
	}
}

int	ft_eat(t_philo *philo)
{
	t_data	*data;
	data = philo->data;
	if (pthread_mutex_lock(&philo->right_fork) != 0)
		return (error_thread("r_fork mutex lock failed", philo->id, data));
	print_status(data, philo->id, FORK);
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (error_thread("l_fork mutex lock failed", philo->id, data));
	print_status(data, philo->id, FORK);
	if (pthread_mutex_lock(&data->death_meal))
		return (error_thread("death mutex lock failed", philo->id, data));
	print_status(data, philo, EAT);
	philo->last_meal_time = ft_get_time();
	if (pthread_mutex_unlock(&data->death_meal))
		return (error_thread("death mutex unlock failed", philo->id, data));
	ft_sleep(data->time_eat, data);
	philo->meals_nb++;
	if (philo->meals_nb == data->times_must_eat)
		philo->finish = TRUE;
	if (pthread_mutex_unlock(&philo->right_fork))
		return (error_thread("r_fork mutex unlock failed", philo->id, data));
	if (pthread_mutex_unlock(philo->left_fork))
		return (error_thread("l_fork mutex unlock failed", philo->id, data));
	return (1);
}

int	activity(t_philo *philo, t_data *data)
{
	if (data->dead_philo == FALSE)
	{	
		if (philo->finish == FALSE)
			if (!ft_eat(philo))
				return (0);
		all_ate_check(data, data->philos_array);
		if (data->all_ate == TRUE || data->dead_philo == TRUE)
			return (0);
		if (!print_status(data, philo, SLEEP))
			return (0);
		ft_sleep(data->time_sleep, data);
		if (data->dead_philo == FALSE)
			if (print_status(data, philo, THINK))
				return (0);
	}
	return (1);		
}
