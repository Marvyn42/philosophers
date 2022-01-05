/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:27:41 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/05 11:55:22 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_list(t_thread **thread)
{
	t_thread		*tmp;
	unsigned int	nb_philo;

	nb_philo = (*thread)->data->number_of_philosophers;
	while (nb_philo)
	{
		tmp = (*thread)->next;
		free(*thread);
		*thread = tmp;
		nb_philo--;
	}
	thread = NULL;
}

t_bool	join_thread(t_thread **thread)
{
	unsigned int	i;

	i = 0;
	while (i < (*thread)->data->number_of_philosophers)
	{
		if (pthread_join((*thread)->philo, NULL) != 0)
			return (FALSE);
		*thread = (*thread)->next;
		i++;
	}
	return (TRUE);
}

t_bool	fork_destroy(t_thread **thread)
{
	unsigned int	i;

	i = 0;
	while (i < (*thread)->data->number_of_philosophers)
	{
		if ((*thread)->data->number_of_philosophers == 1)
			if (pthread_mutex_unlock((*thread)->lfork) != 0)
				return (print_err(err_message(ERR_UNLOCK)));
		if (pthread_mutex_destroy(&((*thread)->rfork)))
			return (print_err(err_message(ERR_DESTROY)));
		*thread = (*thread)->next;
		i++;
	}
	return (TRUE);
}

t_bool	mutex_destroy(t_thread **thread)
{
	unsigned int	i;

	i = 0;
	while (i < (*thread)->data->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&((*thread)->data->lock)) != 0)
			return (print_err(err_message(ERR_DESTROY)));
		if (pthread_mutex_destroy(&((*thread)->data->print)) != 0)
			return (print_err(err_message(ERR_DESTROY)));
		i++;
	}
	return (TRUE);
}

/*
**	suite de fct qui libère la mémoire en fonction de ce qui a été alloué
*/
t_bool	free_data(t_free free_code, t_thread **thread)
{
	if (free_code >= JOIN)
		if (!join_thread(thread))
			return (FALSE);
	if (free_code >= FORK)
		if (!fork_destroy(thread))
			return (FALSE);
	if (free_code >= MUTEX)
		if (!mutex_destroy(thread))
			return (FALSE);
	free_list(thread);
	return (TRUE);
}
