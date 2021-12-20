/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/20 19:24:55 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Libraries */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h> // for threads
# include <string.h> // for memset
# include <unistd.h> // for usleep
# include <sys/time.h> // for gettimeofday

/* Boolean values */
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/* Data in common for all philosophers */
typedef struct s_data
{
	int	nb_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	times_must_eat;
}	t_data;

/* main.c */
int		main(int argc, char **argv);

/* parsing.c */
int		parsing(int argc);

/* init.c */
void	set_data_struct(int num, t_data *data, int arg_nb);

/* utils.c */
int	ft_isdigit(char *str);
int	ft_atoi(const char *str, int *is_toobig);

/* errors.c */
int	error(char *message);
void	*null_error(char *message);
#endif
