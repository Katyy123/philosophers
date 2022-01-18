/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:24:59 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/18 17:15:55 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_data *data, int philo_id, t_status status)
{
	pthread_mutex_lock(&data->print);
	if (data->dead_philo == TRUE)
		usleep(10000);
	if (data->dead_philo == FALSE)
	{
		printf("%lli Philo %d ", ft_get_time() - data->start_time,
			philo_id + 1);
		if (status == FORK)
			printf("has taken a fork\n");
		if (status == EAT)
			printf("\x1b[33m""is eating\n""\x1b[0m");
		if (status == SLEEP)
			printf("\x1b[36m""is sleeping\n""\x1b[0m");
		if (status == THINK)
			printf("\x1b[32m""is thinking\n""\x1b[0m");
		if (status == DIE)
			printf("\x1b[31m""died\n""\x1b[0m");
	}
	pthread_mutex_unlock(&data->print);
}

long long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1e3) + (t.tv_usec * 1e-3));
}

void	ft_sleep(long long time_in_ms, t_data *data)
{
	long long	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < time_in_ms
		&& data->dead_philo == FALSE)
		usleep(500);
}
