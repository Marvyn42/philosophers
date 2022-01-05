/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:26:09 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/05 11:53:59 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Check si un philo ne mange pas à temps
*/
t_bool	is_died(t_thread *thread)
{
	unsigned int	i;

	i = 0;
	while (still_running(thread->data)
		&& i < thread->data->number_of_philosophers)
	{
		if (pthread_mutex_lock(&(thread->data->print)) != 0)
			return (print_err(err_message(ERR_LOCK)));
		if (thread->last_meal + thread->data->time_to_die <= set_time())
		{
			if (pthread_mutex_unlock(&(thread->data->print)) != 0)
				return (print_err(err_message(ERR_UNLOCK)));
			if (!print_mess(thread->data, thread->id, "died"))
				return (FALSE);
			thread->data->stop = 1;
			return (FALSE);
		}
		if (pthread_mutex_unlock(&(thread->data->print)) != 0)
			return (print_err(err_message(ERR_UNLOCK)));
		thread = thread->next;
		i++;
	}
	return (TRUE);
}

/*
**	Check si il faut s'arrêter
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
**	check si tout les philos sont rassasiés
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
			usleep(10);
	}
	thread->data->stop = 1;
	return (FALSE);
}

/*
**	Return TRUE si le philo est rassasié
*/
t_bool	is_satiated(t_thread *thread)
{
	if (thread->data->nb_meal_must_eat && thread->nb_meal
		== thread->data->nb_meal_must_eat)
		return (TRUE);
	return (FALSE);
}

/*
**	Fct qui check si il faut stopper la routine
*/
t_bool	condition_running(t_thread *thread)
{
	unsigned int	i;

	i = 0;
	while (i < thread->data->number_of_philosophers)
	{
		if (thread->data->stop)
			return (FALSE);
		if (!is_died(thread))
			return (FALSE);
		if (thread->data->nb_meal_must_eat)
			if (thread->nb_meal == thread->data->nb_meal_must_eat)
				return (all_satiated(thread));
		thread = thread->next;
		i++;
	}
	return (TRUE);
}
