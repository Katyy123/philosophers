/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:51:21 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:12:35 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	set_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->pid = 0;
	philo->meals_nb = 0;
	philo->data = data;
	sem_unlink("death_meal");
	philo->death_meal = sem_open("death_meal", O_CREAT | \
		O_EXCL, S_IRWXU, 1);
	return (1);
}

int	set_data_2(t_data *data)
{
	if (data->philos_nb > 200)
		return (error("too many philosophers"));
	if (data->time_die < 60 || data->time_eat < 60 || data->time_sleep < 60)
		return (error("philosophers need more time to do that"));
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("stop");
	sem_unlink("eat_enough");
	data->forks = sem_open("forks", O_CREAT | \
		O_EXCL, S_IRWXU, data->philos_nb);
	data->print = sem_open("print", O_CREAT | O_EXCL, S_IRWXU, 1);
	data->stop = sem_open("stop", O_CREAT | O_EXCL, S_IRWXU, 0);
	if (data->times_must_eat != -1)
		data->eat_enough = sem_open("eat_enough", O_CREAT | O_EXCL, S_IRWXU, 0);
	data->phil_arr = malloc(sizeof(t_philo) * data->philos_nb);
	if (!data->phil_arr)
		return (error("phil_arr malloc failed"));
	return (1);
}

int	init(t_data *data)
{
	int	i;

	if (!set_data_2(data))
		return (0);
	i = 0;
	while (i < data->philos_nb)
	{
		if (!set_philo(&data->phil_arr[i], i, data))
			return (0);
		i++;
	}
	return (1);
}

void	set_data_1(int num, t_data *data, int arg_nb)
{
	if (arg_nb == 1)
		data->philos_nb = num;
	else if (arg_nb == 2)
		data->time_die = num;
	else if (arg_nb == 3)
		data->time_eat = num;
	else if (arg_nb == 4)
	{
		data->time_sleep = num;
		data->times_must_eat = -1;
	}
	else if (arg_nb == 5)
		data->times_must_eat = num;
}
