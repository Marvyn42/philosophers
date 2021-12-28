/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/28 14:29:56 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	TODO:	À supprimer
*/
void	printdata(t_thread *thread)
{
	unsigned int	i;

	i = thread->data->number_of_philosophers;
	while (i)
	{
		printf("DATA:\n");
		printf("id = %u\n", thread->id);
		printf("%u\n", thread->data->number_of_philosophers);
		printf("%u\n", thread->data->time_to_die);
		printf("%u\n", thread->data->time_to_eat);
		printf("%u\n", thread->data->time_to_sleep);
		printf("%u\n", thread->data->nb_meal_must_eat);
		printf("\n\n");
		thread = thread->next;
		i--;
	}
}

int	main(int ac, char **av)
{
	t_thread		*thread;
	t_data			data;
	unsigned int	i;

	thread = NULL;
	i = 0;
	if (!parsing(ac, av))
		return (EXIT_FAILURE);
	if (ft_atoi(av[1]) == 0 || (ac == 6 && ft_atoi(av[5]) == 0))
		return (EXIT_SUCCESS);
	if (!initialisation(&thread, &data, av, ac))
		return (EXIT_FAILURE);
	//créer les threads
	while (i < thread->data->number_of_philosophers)
	{
		if (pthread_create(&thread->philo, NULL, philo_routine, thread) != 0)
			return (EXIT_FAILURE);
		thread = thread->next;
		i++;
	}
	//boucler sur les conditions: still_runing
	while ()
	{
		//
	}
	if (!free_data(ALL, thread))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
