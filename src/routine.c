/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:09 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/18 20:44:36 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *thread)
{
	t_thread	*tmp;
	int			i;

	i = 0;
	tmp = thread;
	while (i < tmp->data.number_of_times_each_philosopher_must_eat)
	{
		// printf("timestamp_in_ms %d has taken a fork.\n", tmp->id);
		if (pthread_mutex_lock(&tmp->data.lock) == 0)
		{
			printf("timestamp_in_ms %d is eating.\n", tmp->id);
			usleep(tmp->data.time_to_eat);
			i++;
		}
		if (pthread_mutex_lock(&tmp->data.lock) == 0)
		{
			printf("timestamp_in_ms %d is sleeping.\n", tmp->id);
			usleep(tmp->data.time_to_sleep);
		}
		pthread_mutex_unlock(&tmp->data.lock);
		printf("timestamp_in_ms %d is thinking.\n", tmp->id);
	}
	//is alive ?
	return NULL;
}
		// printf("timestamp_in_ms %d died.\n", tmp->id);
		// usleep(tmp->data.time_to_die);
