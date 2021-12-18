/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:30:20 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/17 01:42:11 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	crée ma liste chainée de N philo.
*/
t_bool	create_philo(int nb_philo, unsigned int *arg, t_thread *thread, int ac)
{
	int			i;
	t_thread	*tmp;
	t_data		data;

	if (!init_data(&data, arg, ac))
		return (FALSE);
	i = 0;
	while (i < nb_philo)
	{
		thread = (t_thread*)malloc(sizeof(t_thread));
		if (!thread)
			return (FALSE);
		if (!i)
			tmp = thread;
		thread->id = i + 1;
		thread->data = data;
		thread = thread->next;
	}
	thread = tmp;
	return (TRUE);
}

/*
**	Initialise les valeurs passé en paramètre à la structure data.
*/
t_bool	init_data(t_data *data, unsigned int *arg, int ac)
{
	data->number_of_philosophers = arg[0];
	data->time_to_die = arg[1];
	data->time_to_eat = arg[2];
	data->time_to_sleep = arg[3];
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = arg[4];
	if (pthread_mutex_init(&(data->lock), NULL))
	{
		printf("Error init mutex");
		return (FALSE);
	}
	return (TRUE);
}

/*
**	rempli mes structures thread et data.
	TODO: RÉDUIRE LIGNE PRINTF
*/
t_bool	set_data(int ac, char **av, t_thread *thread)
{
	unsigned int	*tab_arg;

	tab_arg = (unsigned int*)ft_calloc(ac, sizeof(unsigned int));
	if (!tab_arg)
		return (FALSE);
	if ((ac != 5 && ac != 6) || !ft_isdigit(av, tab_arg))
	{
		free(tab_arg);
		printf("Usage:\n%s <NUM1> <NUM2> <NUM3> <NUM4> (optionnal)<NUM5>.\nNUM can only be a positive integer between 0 and 2147483647, and contain nothing else than a digit.\n", av[0]);
		return (FALSE);
	}
	if (!create_philo(ft_atoi(av[1]), tab_arg, thread, ac))
	{
		free(tab_arg);
		return (FALSE);
	}
	free(tab_arg);
	return (TRUE);
}
