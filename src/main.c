/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/21 17:28:48 by mamaquig         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	unsigned int	i;
	int				ret;
	t_thread		*thread;
	t_bool			tmp;

	thread = NULL;
	tmp = 0;
	if (!set_data(ac, av, &thread))
		return (EXIT_FAILURE);
	ret = 1;
	i = 0;
	printf("DATA dans main avant de close data:\n");
	printdata(thread);
	printf("--------------------------------------------------\n");
	if (!close_data(&thread, tmp))
		return (EXIT_FAILURE);
	printf("Sortie de main fct.\n");
	return (EXIT_SUCCESS);
//---------------------------------------------------------------------------//
	while (ret)
	{
		tmp = 1;
		if (i < thread->data->number_of_philosophers)
		{
			if (pthread_create(&thread->philo, NULL, philo_routine, thread) != 0)
				return (EXIT_FAILURE);
			thread = thread->next;
			i++;
		}
		//faire la boucle ici de alive ?
		// ret = philo_hungry_or_alive(thread);
		// if (ret = -1)
		// 	return (fct_mort_philo(thread));
	}
//---------------------------------------------------------------------------//
	if (!close_data(&thread, tmp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
