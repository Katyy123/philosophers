/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:09:53 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/12 19:48:24 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_check(t_philo *philo)
{
	t_data *data;
	
	data = philo->data;//l'indice dell'array è indifferente
	while (data->dead_philo == FALSE && data->all_ate == FALSE)
	{
		ft_usleep(1);//serve per non far andare la funzione di continuo
		while (data->dead_philo == FALSE)
		{
			if (ft_get_time() - philo->last_meal_time >= data->time_die)
			{
				pthread_mutex_lock(&data->death);
				data->dead_philo = TRUE;
				print_status(data, philo->id, DIE);
				pthread_mutex_unlock(&data->death);
			}	
		}
	}
}

int	eat(t_philo *philo)
{
	t_data	*data;
	data = philo->data;
	if (pthread_mutex_lock(&philo->right_fork) != 0)
		return (error_thread("right fork mutex lock failed", philo->id, data));
	print_status(data, philo->id, FORK);
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (error_thread("left fork mutex lock failed", philo->id, data));
	print_status(data, philo->id, FORK);
	//confronta last_meal_time con time_die
	return (1);
}

void	*thread(void *void_philo)
{
	t_data 	*data;
	t_philo *philo;
	int		id_death_thread;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	if (pthread_create(&id_death_thread, NULL, death_check, philo))
		return (error_mutex("death pthread_create failed", data));
	if (philo->id % 2 != 0)//se l'ID di philo non è pari (conto philos da 0), aspetta a mangiare
		ft_usleep(data->time_eat / 10);
	while (!data->dead_philo)//continuare
	{
		eat(philo);
	}
	//continuare
	if (pthread_detach(id_death_thread) != 0)//oppure pthread_join, vedi
		error_thread("death pthread_join failed", philo->id, data);
}

int	create_threads(t_data *data, t_philo *phil_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		if (pthread_create(&phil_arr[i].thread_id, NULL, thread, &phil_arr[i]) != 0)
			return (error_thread("pthread_create failed", phil_arr[i].id, data));
		i++;
		phil_arr[i].last_meal_time = ft_get_time();
	}
	return (1);
}