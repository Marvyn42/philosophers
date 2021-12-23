/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/23 18:42:16 by mamaquig         ###   ########.fr       */
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
		printf("%u\n", thread->data->number_of_times_each_philosopher_must_eat);
		printf("\n\n");
		thread = thread->next;
		i--;
	}
}

t_bool	all_satiated(t_thread *thread)
{
	unsigned int	i;

	i = 0;
	while (i < thread->data->number_of_philosophers)
	{
		// printf("i = %d\nID %d -> nb_meal = %d\n", i, thread->id, thread->nb_meal);
		if (thread->nb_meal != 0)
			return (FALSE);
		thread = thread->next;
		i++;
	}
	return (TRUE);
}

t_bool	init_data()
{
	//init data
	//init liste chainées
		//init mutex
}

int	main(int ac, char **av)
{
	t_thread		*thread;
	t_data			data;
	unsigned int	i;

	thread = NULL;
	i = 0;
	//parse
	if (!parse_data(ac, av))
		return (EXIT_FAILURE); //TODO:	return une fct d'erreur qui set un message.
	if (ft_atoi(av[1], NULL) == 0 || (ac == 6 && ft_atoi(av[5], NULL) == 0))
		return (EXIT_SUCCESS);
	//init
	if (!init_data())
		return (EXIT_FAILURE); //TODO:	return une fct d'erreur qui set un message.
	//créer les threads
	while (i < thread->data->number_of_philosophers)
	{
		if (pthread_create(&thread->philo, NULL, philo_routine, thread) != 0)
			return (EXIT_FAILURE);
		thread = thread->next;
		i++;
	}
	//boucler sur les conditions
	//free
	return (EXIT_SUCCESS);
}
