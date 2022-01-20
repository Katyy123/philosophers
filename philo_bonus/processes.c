/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:44:56 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:15:13 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death_check(void *void_philo)
{
	t_data		*data;
	t_philo		*philo;
	long long	time_now;

	philo = (t_philo *)void_philo;
	data = philo->data;
	while (1)
	{
		sem_wait(philo->death_meal);
		time_now = ft_get_time();
		if ((time_now - philo->last_meal_time) > data->time_die)
		{
			sem_wait(data->print);
			printf("%lli Philo %d died\n", \
				ft_get_time() - data->start_time, philo->id + 1);
			sem_post(data->stop);
			exit(0);
		}
		sem_post(philo->death_meal);
	}
	return (NULL);
}

void	ft_process(t_philo *philo, t_data *data)
{
	philo->last_meal_time = ft_get_time();
	if (pthread_create(&philo->death_th_id, NULL, &death_check, philo) != 0)
	{
		error_process("death th create failed", philo->id, data);
		sem_post(data->stop);
	}
	pthread_detach(philo->death_th_id);
	data->start_time = ft_get_time();
	while (1)
	{
		ft_eat(philo, data);
		ft_sleep_think(philo, data);
	}
}

void	*eating_check(void *void_data)
{
	t_data	*data;
	int		i;

	data = (t_data *)void_data;
	i = -1;
	sem_wait(data->print);
	while (++i < data->philos_nb)
	{
		sem_post(data->print);
		sem_wait(data->eat_enough);
		sem_wait(data->print);
	}
	sem_post(data->stop);
	return (NULL);
}

int	init_eating_check(t_data *data)
{
	if (data->times_must_eat != -1)
	{
		if (pthread_create(&data->eat_th_id, NULL, &eating_check, data))
			return (error("eat pth_create failed"));
		pthread_detach(data->eat_th_id);
	}
	return (1);
}

int	create_processes(t_data *data, t_philo *ph_arr)
{
	int	i;

	if (!init_eating_check(data))
		return (0);
	i = 0;
	data->start_time = ft_get_time();
	while (i < data->philos_nb)
	{
		ph_arr[i].id = i;
		ph_arr[i].pid = fork();
		if (ph_arr[i].pid == -1)
		{
			while (--i >= 0)
				kill(ph_arr[i].pid, SIGKILL);
			return (error_process("fork failed", ph_arr[i].id, data));
		}
		else if (ph_arr[i].pid == 0)
			ft_process(&ph_arr[i], data);
		i++;
	}
	sem_wait(data->stop);
	return (1);
}
