/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:09 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/23 11:38:06 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *ptr)
{
	t_thread		*thread;

	thread = ptr;
	while (!thread->data->stop && ((thread->data->ac_6 && thread->nb_meal) || !thread->data->ac_6))
	{
		if (!thread->data->stop && pthread_mutex_lock(&thread->data->lock) == 0)
		{
			printf("timestamp_in_ms %u is eating.\nnb_meal = %d.\n", thread->id, thread->nb_meal);
			pthread_mutex_unlock(&thread->data->lock);
			usleep(thread->data->time_to_eat);
			if (thread->data->ac_6)
				thread->nb_meal--;
			pthread_mutex_lock(&thread->data->lock);
			printf("timestamp_in_ms %u is sleeping.\n\n", thread->id);
			pthread_mutex_unlock(&thread->data->lock);
			usleep(thread->data->time_to_sleep);
		}
	}
	// 	// printf("timestamp_in_ms %d has taken a fork.\n", tmp->id);
	// 	printf("timestamp_in_ms %d is thinking.\n", tmp->id);
	//is alive ?
	return NULL;
}
		// printf("timestamp_in_ms %d died.\n", tmp->id);
		// usleep(tmp->data.time_to_die);
