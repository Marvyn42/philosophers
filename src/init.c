/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:26:29 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/03 00:46:49 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_fork(t_thread **thread)
{
	unsigned int	i;
	pthread_mutex_t	*tmp;

	i = 0;
	while (i < (*thread)->data->number_of_philosophers)
	{
		if (pthread_mutex_init(&((*thread)->rfork), NULL))
			return (error(ERR_MUTEX, FORK, thread));
		tmp = &(*thread)->rfork;
		*thread = (*thread)->next;
		i++;
		(*thread)->lfork = tmp;
	}
	return (TRUE);
}

t_bool	init_mutex(t_thread **thread, t_data *data)
{
	if (pthread_mutex_init(&(data->lock), NULL))
		return (error(ERR_MUTEX, MUTEX, thread));
	if (pthread_mutex_init(&(data->print), NULL))
		return (error(ERR_MUTEX, MUTEX, thread));
	return (TRUE);
}

t_bool	create_philo(unsigned int nb_philo, t_thread **thread, t_data *data)
{
	unsigned int	i;
	t_thread		*ptr;

	i = 1;
	*thread = ft_create_elem(data, 1);
	if (!thread)
		return (error(ERR_MALLOC, NONE, NULL));
	ptr = *thread;
	while (i < nb_philo)
	{
		if (!ft_list_push_back(thread, data, i + 1))
			return (error(ERR_MALLOC, LIST, thread));
		i++;
	}
	i = 0;
	while ((*thread)->next)
		*thread = (*thread)->next;
	(*thread)->next = ptr;
	*thread = (*thread)->next;
	return (TRUE);
}

void	init_data(t_data *data, int ac, char **av)
{
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->stop = 0;
	data->philo_set = 0;
	if (ac == 6)
		data->nb_meal_must_eat = ft_atoi(av[5]);
	else
		data->nb_meal_must_eat = 0;
}

t_bool	initialisation(t_thread **thread, t_data *data, char **av, int ac)
{
	init_data(data, ac, av);
	if (!create_philo(data->number_of_philosophers, thread, data))
		return (FALSE);
	if (!init_mutex(thread, data))
		return (FALSE);
	if (!init_fork(thread))
		return (FALSE);
	return (TRUE);
}
