/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/03 02:21:26 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//MAIN:
/*			La boucle se stop quand:
	data->stop est set
	tout le monde à mangé
	un philo meurt, on set donc data->stop
*/

//ROUTINE:
/*			La boucle se stop quand:
	data->stop est set
*/

t_bool	condition_running(t_thread *thread)
{
	unsigned int	i;

	i = 0;
	while (i < thread->data->number_of_philosophers)
	{
		if (thread->data->stop)
			return (FALSE);
		//fct qui check le time_to_eat
		if (thread->data->nb_meal_must_eat)
			if (thread->nb_meal == thread->data->nb_meal_must_eat)
				return (all_satiated(thread));
		thread = thread->next;
		i++;
	}
	return (TRUE);
}
//TODO: Avoir la fct du temps pour check les morts
//TODO: refaire la fct usleep ?
//TODO: refaire la fct gettimeofday ?
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
	while (i < thread->data->number_of_philosophers)
	{
		if (pthread_create(&thread->philo, NULL, philo_routine, thread) != 0)
			return (error(ERR_THREAD, ALL, &thread));
		thread = thread->next;
		i++;
	}
	while (condition_running(thread))
		usleep(100);
	if (!free_data(ALL, &thread))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
