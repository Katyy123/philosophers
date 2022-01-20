/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:00:33 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:08:12 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end(t_data *data, t_philo *phil_arr)
{
	int	i;

	i = 0;
	while (i < data->philos_nb)
	{
		kill(data->phil_arr[i].pid, SIGKILL);
		i++;
	}
	sem_close(data->forks);
	sem_close(data->stop);
	sem_close(data->eat_enough);
	i = 0;
	while (i < data->philos_nb)
	{
		sem_close(data->phil_arr[i].death_meal);
		i++;
	}
	sem_close(data->print);
	free(phil_arr);
}
