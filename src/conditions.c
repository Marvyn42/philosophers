/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:26:09 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/28 03:26:17 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	all_satiated(t_thread *thread)
{
	unsigned int	i;

	i = 0;
	while (i < thread->data->number_of_philosophers)
	{
		// printf("i = %d\nID %d -> nb_meal = %d\n", i, thread->id, thread->nb_meal);
		if (thread->nb_meal != 0)
			return (FALSE);
		thread = thread->next;
		i++;
	}
	return (TRUE);
}
