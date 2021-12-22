/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:30:20 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/21 17:37:29 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		free(data);
		return (FALSE);
	}
	if (pthread_mutex_init(&(data->lock), NULL))
		return (FALSE);
	return (TRUE);
}

/*
**	crée ma liste chainée de N philo.
*/
t_bool	create_philo(unsigned int nb_philo, t_thread **tmp, int ac, char **av)
{
	unsigned int	i;
	t_data			*data;
	t_thread		*ptr;

	data = (t_data *)malloc(sizeof(t_data));
	if (nb_philo == 0 || !init_data(data, ac, av))
		return (FALSE);
	i = 1;
	*tmp = ft_create_elem(data, 1);
	if (!tmp)
		return (FALSE);
	ptr = *tmp;
	while (i < nb_philo)
	{
		ft_list_push_back(tmp, data, i + 1);
		i++;
	}
	i = 0;
	while ((*tmp)->next)
		*tmp = (*tmp)->next;
	(*tmp)->next = ptr;
	*tmp = (*tmp)->next;
	return (TRUE);
}

/*
**	rempli mes structures thread et data.
*/
t_bool	set_data(int ac, char **av, t_thread **thread)
{
	t_bool	ret;

	ft_atoi(av[1], &ret);
	if (ret == 0 || (ac != 5 && ac != 6) || !ft_isdigit(av))
	{
		printf("Usage:\n%s <NUM1> <NUM2> <NUM3> <NUM4> (optionnal)<NUM5>.\n\nN\
UM can only be a positive integer between 0 and 4294967295, and contain nothin\
g else than a digit.\n", av[0]);
		return (FALSE);
	}
	if (ft_atoi(av[1], NULL) == 0 || (ac == 6 && ft_atoi(av[5], NULL) == 0))
		return (FALSE);
	if (!create_philo(ft_atoi(av[1], NULL), thread, ac, av))
		return (FALSE);
	return (TRUE);
}
