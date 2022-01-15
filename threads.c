/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:09:53 by cfiliber          #+#    #+#             */
/*   Updated: 2022/01/15 20:22:45 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_check(void *void_philo)
{
	t_data	*data;
	t_philo	*philo;
	int		i;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	while (data->dead_philo == FALSE && data->all_ate == FALSE)
	{
		if ((ft_get_time() - philo->last_meal_time) >= data->time_die)
		{
			pthread_mutex_lock(&data->death_meal);
			print_status(data, philo->id, DIE);
			data->dead_philo = TRUE;
			i = 0;
			while (i < data->philos_nb)
			{
				pthread_mutex_unlock(&data->philos_array[i].right_fork);
				i++;
			}
			pthread_mutex_unlock(&data->death_meal);//forse il mutex death_meal non deve essere sbloccato se è morto un philo
			return (NULL);
		}
		//ft_sleep(5);//, data);//serve per non far andare la funzione di continuo
	}
	return (NULL);
}

void	*thread(void *void_philo)
{
	t_data 	*data;
	t_philo *philo;
	
	philo = (t_philo *)void_philo;
	data = philo->data;
	pthread_create(&philo->death_thread_id, NULL, death_check, philo);
	if (philo->id % 2 != 0)//se l'ID di philo non è pari (conto philos da 0), aspetta a mangiare
		ft_sleep(data->time_eat / 10);//, data);
	while (data->dead_philo == FALSE)//continuare
	{
		//pthread_create(&philo->death_thread_id, NULL, death_check, philo);
		activity(philo, data);
		pthread_detach(philo->death_thread_id);
		if (data->all_ate == TRUE)
		{
			pthread_mutex_lock(&data->print);
			printf("Philo %d has eaten %d times\n", philo->id + 1, philo->meals_nb);
			//pthread_mutex_unlock(&data->print);
			return (NULL);
		}
		//pthread_detach(philo->death_thread_id);//oppure pthread_join, vedi
	}
	return (NULL);
}

int	create_threads(t_data *data, t_philo *phil_arr)
{
	int	i;
	
	i = 0;
	while (i < data->philos_nb)
	{
		phil_arr[i].last_meal_time = ft_get_time();
		if (pthread_create(&phil_arr[i].thread_id, NULL, thread, &phil_arr[i]) != 0)
			return (error_thread("pthread_create failed", phil_arr[i].id, data));
		i++;
	}
	//if (pthread_create(&data->death_thread_id, NULL, death_check, data->philos_array))
	//{
		//error_mutex("death pthread_create failed", data);
		//return (0);
	//}
	//if (data->all_ate == TRUE)//questo messo qui sarà sempre FALSE. Va messo dopo pthread_join
	//{
			//printf("All philos have eaten %d times", data->nb_philos_ate);
	//}
	//return (1);
}