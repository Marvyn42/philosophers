/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 14:15:42 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	all_thread_set(thread->data);
	while ((still_running(&data) && condition_running(thread)))
		usleep(50);
	if (!free_data(ALL, &thread))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
