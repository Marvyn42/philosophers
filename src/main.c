/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:41:41 by mamaquig          #+#    #+#             */
/*   Updated: 2021/10/21 02:16:16 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_list(t_arg arg)
{
	printf("number_of_philo = %d\n", arg.number_of_philo);
	printf("time_to_die = %d\n", arg.time_to_die);
	printf("time_to_eat = %d\n", arg.time_to_eat);
	printf("time_to_sleep = %d\n", arg.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat = %d\n", arg.number_of_times_each_philosopher_must_eat);
}

int	main(void)
{
	t_arg	arg;

	if (!ask_args(&arg))
	{
		write(1, "Please, write positive interger only.\n", 38);
		return (EXIT_SUCCESS);
	}
	print_list(arg);
	return (EXIT_SUCCESS);
}

//pour gérer le temps ?= int usleep(useconds_t usec);

//usleep into (write(1, str[i], 1)), i++ pour écrire en direct
//la valeur de temps dans uspeed peut être random pour rendre le rendu plus réaliste (valeur minime)
