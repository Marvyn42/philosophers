/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:57:28 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/03 02:20:13 by mamaquig         ###   ########.fr       */
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
	if (pthread_mutex_lock(thread->lfork) != 0)
		return (print_err(err_message(ERR_LOCK)));
	if (!print_mess(thread->data, thread->id, "has taken a fork"))
		return (FALSE);
	if (thread->data->number_of_philosophers == 1)
		return (FALSE);
	if (pthread_mutex_lock(&(thread->rfork)) != 0)
		return (print_err(err_message(ERR_LOCK)));
	if (!print_mess(thread->data, thread->id, "has taken a fork"))
		return (FALSE);
	return (TRUE);
}

/*
**
*/
t_bool	do_eat(t_thread *thread)//TODO: Compter le temps du dernier repas ?
{
	if (!still_running(thread->data))
		return (FALSE);
	if (!print_mess(thread->data, thread->id, "is eating"))
		return (FALSE);
	usleep(thread->data->time_to_eat*1000);//TODO: refaire la fct ?
	thread->nb_meal++;
	if (pthread_mutex_unlock(thread->lfork) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	if (pthread_mutex_unlock(&(thread->rfork)) != 0)
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
	if (!still_running(thread->data))
		return (FALSE);
	if (!print_mess(thread->data, thread->id, "is sleeping"))
		return (FALSE);
	usleep(thread->data->time_to_sleep*1000);//TODO: Refaire la fct ?
	if (!still_running(thread->data))
		return (FALSE);
	return (TRUE);
}
