/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:26:09 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/03 02:20:54 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**
*/
t_bool	still_running(t_data *data)
{
	if (pthread_mutex_lock(&(data->lock)) != 0)
		return (print_err(err_message(ERR_LOCK)));
	if (data->stop == 1)
	{
		if (pthread_mutex_unlock(&(data->lock)) != 0)
			return (print_err(err_message(ERR_UNLOCK)));
		return (FALSE);
	}
	if (pthread_mutex_unlock(&(data->lock)) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (TRUE);
}

/*
**
*/
t_bool	all_satiated(t_thread *thread)
{
	unsigned int	i;

	i = 0;
	while (i < thread->data->number_of_philosophers)
	{
		if (!still_running(thread->data))
			return (FALSE);
		if (thread->nb_meal == thread->data->nb_meal_must_eat)
		{
			thread = thread->next;
			i++;
		}
		else
			usleep(50);
	}
	thread->data->stop = 1;
	return (FALSE);
}
