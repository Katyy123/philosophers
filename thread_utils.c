/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:24:59 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/12 19:29:16 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_data *data, int philo_id, t_status status)
{
	//aggiungere controllo se non è morto nessun philo, in modo che nessun altro possa stampare dopo. bisogna però separare DIE
	if (pthread_mutex_lock(&data->print) != 0)
		return (error_thread("print mutex lock failed", philo_id, data));
	printf("%lli Philo %d ", ft_get_time() - data->start_time, philo_id);
	if (status == FORK)
		printf("has taken a fork\n");
	if (status == EAT)
		printf("\x1b[33m""is eating/n""\x1b[0m");
	if (status == SLEEP)
		printf("\x1b[36m""is sleeping/n""\x1b[0m");
	if (status == THINK)
		printf("\x1b[32m""is thinking/n""\x1b[0m");
	if (status == DIE)
		printf("\x1b[31m""died/n""\x1b[0m");
	if (pthread_mutex_unlock(&data->print) != 0)
		return (error_thread("print mutex unlock failed", philo_id, data));
	return (1);
}

long long	time_diff(long long start, long long end)
{
	return (end - start);
}

long long	ft_get_time(void)
{
	struct timeval	t;
	if (gettimeofday(&t, NULL) != -1)
		return ((t.tv_sec * 1e3) + (t.tv_usec * 1e-3));
}

void	ft_usleep(long long time_in_ms)
{
	long long	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < time)
		usleep(time_in_ms / 10);
}