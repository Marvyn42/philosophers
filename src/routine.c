/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:09 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/03 02:19:39 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**
*/
t_bool	all_thread_set(t_data *data)
{
	//mettre un timer pour quitter au bout de 1 seconde. Càd qu'il y a erreur
	data->philo_set++;
	while (TRUE)
	{
		if (pthread_mutex_lock(&data->lock) != 0)
			return (print_err(err_message(ERR_LOCK)));
		if (data->philo_set == data->number_of_philosophers)
			break ;
		if (pthread_mutex_unlock(&data->lock) != 0)
			return (print_err(err_message(ERR_UNLOCK)));
	}
	if (pthread_mutex_unlock(&data->lock) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (TRUE);
}

/*
**
*/
t_bool	is_satiated(t_thread *thread)
{
	if (thread->data->nb_meal_must_eat && thread->nb_meal == thread->data->nb_meal_must_eat)
		return (TRUE);
	return (FALSE);
}

/*
**
*/
void	*philo_routine(void *ptr)
{
	t_thread		*thread;

	thread = ptr;
	if (!all_thread_set((thread->data)))
		return (NULL);
	if (thread->id % 2)
		usleep(100);
	while (still_running(thread->data))
	{
		if (!is_satiated(thread))
			if (!do_think(thread))
				return (NULL);
		if (!is_satiated(thread))
			if (!do_eat(thread))
				return (NULL);
		if (!is_satiated(thread))
			if (!do_sleep(thread))
				return (NULL);
	}
	return (NULL);
}
