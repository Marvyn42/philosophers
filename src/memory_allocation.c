/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:21:39 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/22 17:11:37 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)malloc(size * count);
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

void	ft_free(t_thread **thread)
{
	t_thread		*tmp;
	unsigned int	nb_philo;

	nb_philo = (*thread)->data->number_of_philosophers;
	free((*thread)->data);
	while (nb_philo-- != 0 && thread)
	{
		tmp = (*thread)->next;
		free(*thread);
		*thread = tmp;
	}
	thread = NULL;
}

t_bool	close_data(t_thread **thread, t_bool tmp)
{
	unsigned int	i;

	i = 0;
	while (tmp && i < (*thread)->data->number_of_philosophers)
	{
		if (pthread_join((*thread)->philo, NULL) != 0)
			return (FALSE);
		*thread = (*thread)->next;
		i++;
	}
	pthread_mutex_destroy(&((*thread)->data->lock));
	ft_free(thread);
	printf("Tout est free.\n");
	return (TRUE);
}
