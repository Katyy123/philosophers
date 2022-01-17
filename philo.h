/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:30 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/17 20:05:40 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Libraries */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <dlfcn.h>

/* Boolean values */
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/* Status of philosophers */
typedef enum e_status
{
	FORK = 1,
	EAT = 2,
	SLEEP = 3,
	THINK = 4,
	DIE = 5,
}	t_status;

/* Specific data for every philosopher */
typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	int				meals_nb;
	long long		last_meal_time;
	struct s_data	*data;
	pthread_t		death_th_id;
	t_bool			finish;
}	t_philo;

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
	int				nb_philos_ate;
	pthread_mutex_t	print;
	pthread_mutex_t	death_meal;
	pthread_mutex_t	death_sleep;
	pthread_mutex_t	death_think;
	t_philo			*phil_arr;
	long long		start_time;
}	t_data;

/* main.c */
int			main(int argc, char **argv);

/* parsing.c */
int			parsing(int argc, char **argv, t_data *data);
int			check_num(int num, int *is_toobig);
int			ft_is_toobig(int *is_toobig);

/* init.c */
void		set_data_1(int num, t_data *data, int arg_nb);
int			init(t_data *data);
int			set_data_2(t_data *data);
int			set_philo(t_philo *philo, int i, t_data *data);

/* thread.c */
int			create_threads(t_data *data, t_philo *phil_arr);
void		*thread(void *void_philo);
void		*death_check(void *philo);

/* philos_activity.c */
int			activity(t_philo *philo, t_data *data);
void		ft_eat(t_philo *philo);
void		all_ate_check(t_data *data);

/* thread_utils.c */
void		ft_sleep(long long time_in_ms, t_data *data);
long long	ft_get_time(void);
void		print_status(t_data *data, int philo_id, t_status status);

/* end.c */
int			end(t_data *data, t_philo *philos_arr);
int			destroy_mutexes(t_data *data, t_philo *philo_arr);

/* utils.c */
int			ft_isdigit(char *str);
int			ft_atoi(const char *str, int *is_toobig);

/* errors.c */
int			error(char *message);
int			error_thread(char *message, int philo_id, t_data *data);
int			error_mutex(char *message, t_data *data);
void		*error_th_null(char *message, int philo_id, t_data *data);
#endif
