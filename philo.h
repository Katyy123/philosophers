/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/21 19:30:47 by cfiliber         ###   ########.fr       */
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
# include <dlfcn.h>

/* Boolean values */
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/* Data in common for all philosophers */
typedef struct s_data
{
	int				philos_nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_must_eat;
	t_bool			dead_philo;
	t_bool			all_ate;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				thread_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_nb;
	long long		last_meal_time;
}	t_philo;

/* main.c */
int		main(int argc, char **argv);

/* parsing.c */
int		parsing(int argc, char **argv, t_data *data);

/* init.c */
void	set_data_1(int num, t_data *data, int arg_nb);
int		set_data_2(t_data *data);
int		init(t_data *data, t_philo *philo);
void	set_philo(t_philo *philo, int i);
int		init_mutex(t_data *data, t_philo *philo);

/* utils.c */
int		ft_isdigit(char *str);
int		ft_atoi(const char *str, int *is_toobig);

/* errors.c */
int		error(char *message);
void	*null_error(char *message);
#endif
