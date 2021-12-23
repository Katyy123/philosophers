/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:09:00 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/23 17:53:26 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *message)
{
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	return (NULL);
}

int	error_thread(char *message, int philo_id)
{
	printf("\x1b[31m""Error:\n%s(Philo %d)\n""\x1b[0m", message, philo_id);
	return (0);
}
