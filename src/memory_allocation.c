/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:21:39 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/20 14:04:56 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char*)malloc(size * count);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size * count)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	ft_free(t_thread *thread)
{
	t_thread	*tmp;

	while (thread)
	{
		tmp = thread->next;
		free(thread);
		thread = tmp;
	}
}

t_bool	close_data(t_thread *thread)
{
	unsigned int	i;

	i = 0;
	while (i < thread->data.number_of_philosophers)
	{
		if (pthread_join(thread->philo, NULL) != 0)
			return (FALSE);
		thread = thread->next;
		i++;
	}
	pthread_mutex_destroy(&(thread->data.lock));
	ft_free(thread);
	return (TRUE);
}
