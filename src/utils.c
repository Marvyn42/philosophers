/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:18:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/05 11:47:53 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	usleep plus précis
*/
void	ft_usleep(t_data *data, unsigned int us)
{
	unsigned int	now;

	now = set_time();
	while (still_running(data) && set_time() < now + us / 1000)
		usleep(10);
}

/*
**	Affiche les messages sur l'entrée standard
*/
t_bool	print_mess(t_data *data, unsigned int philo_id, char *to_do)
{
	if (!still_running(data))
		return (TRUE);
	if (pthread_mutex_lock(&(data->print)) != 0)
		return (print_err(err_message(ERR_LOCK)));
	printf("%u\t%u %s\n", set_time(), philo_id, to_do);
	if (pthread_mutex_unlock(&(data->print)) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (TRUE);
}

/*
**	char to int
*/
unsigned int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res);
}
