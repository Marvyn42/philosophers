/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:15:32 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/22 13:50:16 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thread	*ft_create_elem(t_data *data, unsigned int id)
{
	t_thread	*tmp;

	tmp = (t_thread *)malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->id = id;
	tmp->is_dead = 0;
	tmp->nb_meal = data->number_of_times_each_philosopher_must_eat;
	tmp->next = NULL;
	return (tmp);
}

void	ft_list_push_back(t_thread **begin_list, t_data *data, unsigned int id)
{
	t_thread	*current;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data, id);
		return ;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = ft_create_elem(data, id);
}
