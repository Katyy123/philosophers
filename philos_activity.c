/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_activity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:16:48 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/15 22:01:56 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_ate_check(t_data *data)//, t_philo *phil_arr)
{
	if (data->nb_philos_ate == data->philos_nb)
		data->all_ate = TRUE;
	//while (i < data->philos_nb)
	//{
		//if (phil_arr[i].finish == FALSE)
		//{
			//data->all_ate = FALSE;
			//break ;
		//}
		//else
			//data->all_ate = TRUE;
		//i++;
	//}
}

void	ft_eat(t_philo *philo)
{
	t_data	*data;
	data = philo->data;
	pthread_mutex_lock(&philo->right_fork);
		//return (error_thread("r_fork mutex lock failed", philo->id, data));
	print_status(data, philo->id, FORK);
	pthread_mutex_lock(philo->left_fork);
		//return (error_thread("l_fork mutex lock failed", philo->id, data));
	print_status(data, philo->id, FORK);
	pthread_mutex_lock(&philo->eating);
	pthread_mutex_lock(&data->death_meal);//potrebbe essere non necessario questo mutex
		//return (error_thread("death mutex lock failed", philo->id, data));
	print_status(data, philo->id, EAT);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&data->death_meal);
		//return (error_thread("death mutex unlock failed", philo->id, data));
	ft_sleep(data->time_eat);//, data);
	philo->meals_nb++;
	//printf("meals_nb (philo %d) = %d\n", philo->id + 1, philo->meals_nb);
	//printf("times_must_eat (philo %d) = %d\n", philo->id + 1, data->times_must_eat);
	if (philo->meals_nb == data->times_must_eat)
	{
		philo->finish = TRUE;
		data->nb_philos_ate++;
	}
	pthread_mutex_unlock(&philo->right_fork);
		//return (error_thread("r_fork mutex unlock failed", philo->id, data));
	pthread_mutex_unlock(philo->left_fork);
		//return (error_thread("l_fork mutex unlock failed", philo->id, data));
}

int	activity(t_philo *philo, t_data *data)
{
	if (data->dead_philo == FALSE)
	{	
		if (philo->finish == FALSE)
			ft_eat(philo);
		all_ate_check(data);//, data->philos_array);
		if (data->all_ate == TRUE || data->dead_philo == TRUE)
			return (1);
		print_status(data, philo->id, SLEEP);
		ft_sleep(data->time_sleep);//, data);
		if (data->dead_philo == FALSE)
			print_status(data, philo->id, THINK);
	}
	return (1);		
}
