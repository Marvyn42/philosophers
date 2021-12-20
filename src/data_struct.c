/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:30:20 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/20 18:33:02 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	crée ma liste chainée de N philo.
*/
t_bool	create_philo(int nb_philo, t_thread *thread, int ac, char **av)
{
	int			i;
	t_thread	*tmp;
	t_data		data;

	if (!init_data(&data, ac, av))
	{
		printf("FUCK\n");
		return (FALSE);
	}
	i = 0;
	while (i < nb_philo)
	{
		thread = (t_thread*)malloc(sizeof(t_thread));
		if (!thread)
		{
			printf("FUCK\n");
			return (FALSE);
		}
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
t_bool	init_data(t_data *data, int ac, char **av)
{
	t_bool	ret;

	ret = 1;
	data->number_of_philosophers = ft_atoi(av[1], &ret);
	data->time_to_die = ft_atoi(av[2], &ret);
	data->time_to_eat = ft_atoi(av[3], &ret);
	data->time_to_sleep = ft_atoi(av[4], &ret);
	if (ac == 6)
	{
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5], &ret);
		data->ac_6 = 1;
	}
	else
		data->ac_6 = 0;
	if (!ret)
	{
		printf("FUCK\n");
		return (FALSE);
	}
	if (pthread_mutex_init(&(data->lock), NULL))
	{
		printf("Error init mutex");
		return (FALSE);
	}
	return (TRUE);
}

/*
**	rempli mes structures thread et data.
*/
t_bool	set_data(int ac, char **av, t_thread *thread)
{
	if ((ac < 5 || ac > 6))
	{
		printf("Usage:\n%s <NUM1> <NUM2> <NUM3> <NUM4> (optionnal)<NUM5>.\n\nNUM can only be a positive \
integer between 1 and 4294967295, and contain nothing else than a digit.\n", av[0]);
		return (FALSE);
	}
	if (!ft_isdigit(av))
	{
		printf("ptn relou\n");
		return (FALSE);
	}
	if (!create_philo(ft_atoi(av[1], NULL), thread, ac, av))
	{
		printf("NTM\n");
		return (FALSE);
	}
	return (TRUE);
}
