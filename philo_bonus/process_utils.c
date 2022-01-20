/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:45:15 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:07:05 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
void	print_status(t_data *data, int philo_id, t_status status)
{
	if (status != DIE)
		sem_wait(data->print);
	printf("%lli Philo %d ", ft_get_time() - data->start_time,
		philo_id + 1);
	if (status == FORK)
		printf("has taken a fork\n");
	if (status == EAT)
		printf("is eating\n");
	if (status == SLEEP)
		printf("is sleeping\n");
	if (status == THINK)
		printf("is thinking\n");
	if (status == DIE)
		printf("died\n");
	if (status != DIE)
		sem_post(data->print);
}
*/

long long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1e3) + (t.tv_usec * 1e-3));
}

void	ft_sleep(long long time_in_ms)
{
	long long	start_time;

	start_time = ft_get_time();
	usleep(time_in_ms * 920);
	while ((ft_get_time() - start_time) < time_in_ms)
		usleep(time_in_ms * 3);
}
