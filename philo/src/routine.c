/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:09 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/28 19:07:25 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	attend la création de tout les threads
*/
t_bool	all_thread_set(t_data *data)
{
	if (pthread_mutex_lock(&data->lock) != 0)
		return (print_err(err_message(ERR_LOCK)));
	data->philo_set++;
	if (pthread_mutex_unlock(&data->lock) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	while (TRUE)
	{
		if (pthread_mutex_lock(&data->lock) != 0)
			return (print_err(err_message(ERR_LOCK)));
		if (data->philo_set == data->number_of_philosophers + 1)
			break ;
		if (pthread_mutex_unlock(&data->lock) != 0)
			return (print_err(err_message(ERR_UNLOCK)));
	}
	if (pthread_mutex_unlock(&data->lock) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (TRUE);
}

/*
**	programme appliqué par chaque philo
*/
void	*philo_routine(void *ptr)
{
	t_thread		*thread;

	thread = ptr;
	if (!all_thread_set((thread->data)))
		return (NULL);
	if (thread->id % 2)
		usleep(150 * thread->data->number_of_philosophers);
	while (still_running(thread->data))
	{
		if (not_satiated(thread))
		{
			if (still_running(thread->data) && !do_think(thread))
				return (NULL);
			if (!do_eat(thread))
				return (NULL);
			if (still_running(thread->data) && !do_sleep(thread))
				return (NULL);
		}
	}
	return (NULL);
}
