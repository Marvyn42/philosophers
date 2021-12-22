/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/22 17:22:47 by mamaquig         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	unsigned int	i;
	t_thread		*thread;
	t_bool			tmp;

	thread = NULL;
	tmp = 0;
	i = 0;
	if (!set_data(ac, av, &thread))
		return (EXIT_FAILURE);
	while (i < thread->data->number_of_philosophers)
	{
		if (pthread_create(&thread->philo, NULL, philo_routine, thread) != 0)
			return (EXIT_FAILURE);
		thread = thread->next;
		i++;
	}
	i = 0;
	while (!tmp && thread)
	{
		if (thread->is_dead)
			{
		// 		//print un message de mort du thread, et ne rien afficher d'autre (set stop à 1)
		// 		//la boucle du thread qui est conditionné par (check_stop || check_fini de manger N fois) prendra fin = fin du thread.
		// 		thread->data->stop = 1;
			}
		usleep(100);//sleep pour ne pas surcharger le CPU lors de la boucle.
		if (thread->nb_meal == 0)
		{
			usleep(100);//sleep pour laisser le temps aux threads de finir de manger
			if (all_satiated(thread))
			{
				printf("Ils ont tous mangé\n");
				tmp = 1;
			}
		}
		thread = thread->next;
		i++;
	}
	if (!close_data(&thread, tmp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
**	printf("DATA dans main avant de close data:\n");
**	printdata(thread);
**	printf("--------------------------------------------------\n");
**	if (!close_data(&thread, tmp))
**		return (EXIT_FAILURE);
**	printf("Sortie de main fct.\n");
**	return (EXIT_SUCCESS);
*/
