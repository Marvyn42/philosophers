/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:26:09 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/07 19:04:41 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	stop_simulation(t_thread *thread)
{
	if (pthread_mutex_lock(&thread->data->lock) != 0)
			return (print_err(err_message(ERR_LOCK)));
	thread->data->stop = 1;
	if (pthread_mutex_unlock(&(thread->data->lock)) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (TRUE);
}

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
		if (pthread_mutex_lock(&thread->plock) != 0)
			return (print_err(err_message(ERR_LOCK)));
		if (thread->last_meal + thread->data->time_to_die <= set_time(thread->data))
		{
			if (pthread_mutex_unlock(&(thread->plock)) != 0)
				return (print_err(err_message(ERR_UNLOCK)));
			print_mess(thread->data, thread->id, "died");
			stop_simulation(thread);
			return (FALSE);
		}
		if (pthread_mutex_unlock(&thread->plock) != 0)
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
t_bool	not_satiated(t_thread *thread)
{
	if (!still_running(thread->data))
		return (FALSE);
	if (thread->data->nb_meal_must_eat == 0)
		return (TRUE);
	if (pthread_mutex_lock(&thread->plock) != 0)
		return (print_err(err_message(ERR_LOCK)));
	if (thread->nb_meal == thread->data->nb_meal_must_eat)
	{
		if (pthread_mutex_unlock(&thread->plock) != 0)
			return (print_err(err_message(ERR_UNLOCK)));
		return (FALSE);
	}
	if (pthread_mutex_unlock(&thread->plock) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (TRUE);
}

/*
**	Fct qui check si il faut stopper la routine
*/
t_bool	condition_running(t_thread *thread)
{
	unsigned int	i;
	unsigned int	satiatied;

	i = 0;
	satiatied = 0;
	while (i < thread->data->number_of_philosophers)
	{
		if (!still_running(thread->data) || !is_died(thread))
			return (FALSE);
		if (thread->data->nb_meal_must_eat != 0)
		{
			if (pthread_mutex_lock(&thread->plock) != 0)
				return (print_err(err_message(ERR_LOCK)));
			if (thread->nb_meal == thread->data->nb_meal_must_eat)
				satiatied++;
			if (pthread_mutex_unlock(&thread->plock) != 0)
				return (print_err(err_message(ERR_UNLOCK)));
		}
		thread = thread->next;
		i++;
	}
	if (satiatied == thread->data->number_of_philosophers)
	{
		stop_simulation(thread);
		return (FALSE);
	}
	return (TRUE);
}
