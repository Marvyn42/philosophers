/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:15:32 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/04 00:49:47 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Crée un maillion de liste
*/
t_thread	*ft_create_elem(t_data *data, unsigned int id)
{
	t_thread	*tmp;

	tmp = (t_thread *)malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->id = id;
	tmp->is_dead = 0;
	tmp->nb_meal = 0;
	tmp->last_meal = 0;
	tmp->next = NULL;
	return (tmp);
}

/*
**	Ajoute un maillon en bout de liste
*/
t_bool	ft_list_push_back(t_thread **begin_list, t_data *data, unsigned int id)
{
	t_thread	*current;

	if (*begin_list == NULL)
		return (error(ERR_LIST, LIST, begin_list));
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = ft_create_elem(data, id);
	if (!current->next)
		return (error(ERR_LIST, LIST, begin_list));
	return (TRUE);
}
