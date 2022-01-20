/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:45:27 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:03:41 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error(char *message)
{
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	return (0);
}

int	error_process(char *message, int philo_id, t_data *data)
{
	sem_wait(data->print);
	printf("\x1b[31m""Error:\n%s(Philo %d)\n""\x1b[0m", message, philo_id);
	sem_post(data->print);
	return (0);
}
