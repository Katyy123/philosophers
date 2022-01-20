/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_activity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:45:57 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:12:54 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"		

void	ft_eat(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	sem_wait(data->forks);
	sem_wait(data->print);
	printf("%lli Philo %d has taken a fork\n", \
		ft_get_time() - data->start_time, philo->id + 1);
	printf("%lli Philo %d has taken a fork\n", \
		ft_get_time() - data->start_time, philo->id + 1);
	sem_post(data->print);
	sem_wait(philo->death_meal);
	sem_wait(data->print);
	printf("%lli Philo %d is eating\n", ft_get_time() - data->start_time, \
		philo->id + 1);
	sem_post(data->print);
	philo->last_meal_time = ft_get_time();
	sem_post(philo->death_meal);
	philo->meals_nb += 1;
	if (data->times_must_eat == philo->meals_nb)
		sem_post(data->eat_enough);
	ft_sleep(data->time_eat);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	ft_sleep_think(t_philo *philo, t_data *data)
{
	sem_wait(data->print);
	printf("%lli Philo %d is sleeping\n", \
		ft_get_time() - data->start_time, philo->id + 1);
	sem_post(data->print);
	ft_sleep(data->time_sleep);
	sem_wait(data->print);
	printf("%lli Philo %d is thinking\n", \
		ft_get_time() - data->start_time, philo->id + 1);
	sem_post(data->print);
}
