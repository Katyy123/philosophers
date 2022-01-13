/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:30 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/13 19:05:51 by cfiliber         ###   ########.fr       */
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
	int				thread_id;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	int				meals_nb;//number of meals
	long long		last_meal_time;
	struct s_data	*data;
	int				death_thread_id;
	t_bool			finish;//1 when a philo ate m_eat times, if not, 0
}	t_philo;

/* Data in common for all philosophers */
typedef struct s_data
{
	int				philos_nb;
	int				time_die;//time to die
	int				time_eat;
	int				time_sleep;
	int				times_must_eat;
	t_bool			dead_philo;//TRUE if 1 philo dies
	t_bool			all_ate;//inizializzare
	int				nb_philos_ate;//inizializzare //numero di philos che hanno mangiato times_must_eat times
	pthread_mutex_t	print;
	pthread_mutex_t	death_meal;//correggere inizializzazione
	t_philo			*philos_array;
	long long		start_time;
}	t_data;

/* main.c */
int			main(int argc, char **argv);

/* parsing.c */
int			parsing(int argc, char **argv, t_data *data);
int			ft_is_toobig(int *is_toobig);
int			check_num(int num, int *is_toobig);

/* init.c */
void		set_data_1(int num, t_data *data, int arg_nb);
int			set_data_2(t_data *data);
int			init(t_data *data);
int			set_philo(t_philo *philo, int i, t_data *data);

/* thread.c */
int			*thread(void *void_philo);
int			create_threads(t_data *data, t_philo *phil_arr);

/* thread_utils.c */
int			print_status(t_data *data, int philo_id, t_status status);
//int			death_check(t_data *data);
long long	time_diff(long long start, long long end);
long long	ft_get_time(void);
void		ft_usleep(long long time_in_ms, t_data *data);

/* utils.c */
int			ft_isdigit(char *str);
int			ft_atoi(const char *str, int *is_toobig);

/* errors.c */
int			error(char *message);
void		*null_error(char *message, t_data *data);
int			error_thread(char *message, int philo_id, t_data *data);
#endif
