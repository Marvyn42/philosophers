/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:28:22 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/07 19:09:47 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Renvoi l'horodatage.
*/
unsigned int	set_time(t_data *data)
{
	struct timeval		tv;
	static unsigned int	start = 0;

	gettimeofday(&tv, NULL);
	if (pthread_mutex_lock(&data->lock) != 0)
		return (print_err(err_message(ERR_LOCK)));
	if (!start)
		start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (pthread_mutex_unlock(&data->lock) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}
