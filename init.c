/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:00:26 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/22 13:47:06 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->meals_nb = 0;
	philo->last_meal_time = -1;
	if (pthread_mutex_init(&philo->right_fork, NULL) != 0)
		return (error("left_fork mutex initialization failed"));
	if (i != data->philos_nb - 1)
		philo->left_fork = &data->philos_array[i + 1].right_fork;
	else
		philo->left_fork = &data->philos_array[0].right_fork;
	return (1);
}

int	set_data_2(t_data *data)
{
	if (data->philos_nb > 200)
		return (error("too many philosophers"));
	data->dead_philo = FALSE;
	data->all_ate = FALSE;
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (error("print mutex initialization failed"));
	data->philos_array = malloc(sizeof(t_philo) * data->philos_nb);
	if (!data->philos_array)
		return (error("philos_array malloc failed"));
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
		if (!set_philo(&data->philos_array[i], i, data))
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
	//printf("nb_philos: %d\n", data->nb_philos);
	//printf("time_die: %d\n", data->time_die);
	//printf("time_eat: %d\n", data->time_eat);
	//printf("time_sleep: %d\n", data->time_sleep);
	//printf("times_must_eat: %d\n", data->times_must_eat);
}
