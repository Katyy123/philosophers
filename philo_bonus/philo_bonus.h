/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:31:41 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/20 17:05:53 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/* Libraries */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <dlfcn.h>
# include <semaphore.h>
# include <errno.h>
# include <sys/time.h>
# include <fcntl.h>
# include <signal.h>

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
	pid_t			pid;
	int				meals_nb;
	long long		last_meal_time;
	struct s_data	*data;
	pthread_t		death_th_id;
	sem_t			*death_meal;
}	t_philo;

/* Data in common for all philosophers */
typedef struct s_data
{
	int				philos_nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_must_eat;
	sem_t			*print;
	sem_t			*forks;
	sem_t			*stop;
	sem_t			*eat_enough;
	t_philo			*phil_arr;
	long long		start_time;
	pthread_t		eat_th_id;
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

/* processes.c */
int			create_processes(t_data *data, t_philo *ph_arr);
int			init_eating_check(t_data *data);//ho tolto static
void		*eating_check(void *void_data);
void		ft_process(t_philo *philo, t_data *data);
void		*death_check(void *void_philo);

/* philos_activity.c */
void		ft_eat(t_philo *philo, t_data *data);
void		ft_sleep_think(t_philo *philo, t_data *data);

/* process_utils.c */
void		ft_sleep(long long time_in_ms);
long long	ft_get_time(void);
//void		print_status(t_data *data, int philo_id, t_status status);

/* end.c */
void		end(t_data *data, t_philo *philos_arr);

/* utils.c */
int			ft_isdigit(char *str);
int			ft_atoi(const char *str, int *is_toobig);

/* errors.c */
int			error(char *message);
int			error_process(char *message, int philo_id, t_data *data);

#endif
