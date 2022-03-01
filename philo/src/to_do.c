/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:57:28 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 14:11:04 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Pense. Puis prend les deux fourchettes à disposition.
*/
t_bool	do_think(t_thread *thread)
{
	if (!still_running(thread->data))
		return (FALSE);
	if (!print_mess(thread->data, thread->id, "is thinking"))
		return (FALSE);
	if (thread->id % 2)
		usleep(150 * thread->data->number_of_philosophers);
	if (pthread_mutex_lock(thread->lfork) != 0)
		return (print_err(err_message(ERR_LOCK)));
	if (!print_mess(thread->data, thread->id, "has taken a fork"))
		return (FALSE);
	if (thread->data->number_of_philosophers == 1)
	{
		if (pthread_mutex_unlock(thread->lfork) != 0)
			return (print_err(err_message(ERR_UNLOCK)));
		return (FALSE);
	}
	if (pthread_mutex_lock(&thread->rfork) != 0)
		return (print_err(err_message(ERR_LOCK)));
	if (!print_mess(thread->data, thread->id, "has taken a fork"))
		return (FALSE);
	return (TRUE);
}

/*
**
*/
t_bool	do_eat(t_thread *thread)
{
	unsigned int	start;

	if (!print_mess(thread->data, thread->id, "is eating"))
		return (FALSE);
	if (pthread_mutex_lock(&thread->plock) != 0)
		return (print_err(err_message(ERR_LOCK)));
	thread->last_meal = set_time(thread->data);
	thread->nb_meal++;
	if (pthread_mutex_unlock(&thread->plock) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	start = set_time(thread->data);
	while (still_running(thread->data) && set_time(thread->data) - start
		< thread->data->time_to_eat)
		usleep(100);
	if (pthread_mutex_unlock(thread->lfork) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	if (pthread_mutex_unlock(&thread->rfork) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	if (!still_running(thread->data))
		return (FALSE);
	return (TRUE);
}

/*
**
*/
t_bool	do_sleep(t_thread *thread)
{
	unsigned int	start;

	if (!still_running(thread->data))
		return (FALSE);
	if (!print_mess(thread->data, thread->id, "is sleeping"))
		return (FALSE);
	start = set_time(thread->data);
	while (still_running(thread->data) && set_time(thread->data) - start
		< thread->data->time_to_sleep)
		usleep(100);
	if (!still_running(thread->data))
		return (FALSE);
	return (TRUE);
}
