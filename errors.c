/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:09:00 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/15 15:37:02 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *message)
{
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	return (0);
}

int	error_thread(char *message, int philo_id, t_data *data)
{
	pthread_mutex_lock(&data->print);
	printf("\x1b[31m""Error:\n%s(Philo %d)\n""\x1b[0m", message, philo_id);
	pthread_mutex_unlock(&data->print);
	return (0);
}

int	error_mutex(char *message, t_data *data)
{
	pthread_mutex_lock(&data->print);
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	pthread_mutex_unlock(&data->print);
	return (0);
}
