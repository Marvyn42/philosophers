/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:09 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/15 13:27:04 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	*philo_routine(void *data)
{
	t_data	*tmp;
	int		i;

	i = 0;
	tmp = data;
	//pthread_mutex_unlock(&tmp->lock);
	//pthread_mutex_lock(&tmp->lock);
	while (i < tmp->nb_of_philo)
	{
		printf("Philo %d is sleeping.\n", tmp->id);
		//usleep();
		printf("Philo %d is thinking.\n", tmp->id);
		//usleep();
		printf("Philo %d is eating.\n", tmp->id);
		//usleep();
		i++;
	}
	//is alive ?
	return NULL;
}
