/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:50:09 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/18 16:35:59 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	**thread1(void *mutex)
{
	char	*ret;
	char	a = 'b';

	
	ret = malloc(sizeof(char) * 2);
	ret = &a;
	ret[1] = '\0'
	pthread_exit(&ret);
}

int	main()
{
	pthread_t		t_id1;
	pthread_t		t_id2;
	pthread_mutex_t mutex;
	int				*ptr;
	
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t_id1, NULL, thread1, (void *)&mutex);
	pthread_create(&t_id2, NULL, thread2, (void *)&mutex);
	pthread_join(t_id1, (void **)&ptr);
	pthread_join(t_id1, (void **)&ptr);
}
