/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:23:44 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/20 19:25:54 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	//t_data data;
	
	if (argc != 5 && argc != 6)
		return (error("invalid number of arguments"));
	else
	{
		if (!parsing(argc))
			return(-1);
	}
	printf("%s", argv[1]);
}
