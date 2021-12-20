/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:00:26 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/20 17:10:06 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_data_struct(int num, t_data *data, int arg_nb)
{
	if (arg_nb == 1)
		data->nb_philos = num;
	if (arg_nb == 2)
		data->time_die = num;
	if (arg_nb == 3)
		data->time_eat = num;
	if (arg_nb == 4)
		data->time_sleep = num;
	if (arg_nb == 5)
		data->times_must_eat = num;
}
