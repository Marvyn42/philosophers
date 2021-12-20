/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/21 00:12:50 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//int		fct_mort_philo()
//{
//	//set 3 value: -1 philo mort, 0 les philo ont assez mangés, 1 rien a changé
//}
//
//char	philo_hungry_or_alive()
//{
//	//set une data pour savoir si on doit stop ou non
//	//faire un tour de liste pour check cette data
//}

void	printdata(t_data data)
{
	printf("%d\n", data.number_of_philosophers);
	printf("%d\n", data.time_to_die);
	printf("%d\n", data.time_to_eat);
	printf("%d\n", data.time_to_sleep);
	printf("%d\n", data.number_of_times_each_philosopher_must_eat);
}

int	main(int ac, char **av)
{
	unsigned int	i;
	int				ret;
	t_thread		*thread;

	thread = NULL;
	if (!set_data(ac, av, thread))
		return (EXIT_FAILURE);
	ret = 1;
	i = 0;
	printdata(thread->data);
//---------------------------------------------------------------------------//
	while (ret)
	{
		if (i < thread->data.number_of_philosophers)
		{
			if (pthread_create(&(thread->philo), NULL, philo_routine, thread) != 0)
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
	if (!close_data(thread))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
