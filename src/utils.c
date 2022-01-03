/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:18:10 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/03 00:54:32 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_mess(t_data *data, unsigned int philo_id, char *to_do)
{
	if (!still_running(data))
		return (TRUE);
	if (pthread_mutex_lock(&(data->print)) != 0)
		return (print_err(err_message(ERR_LOCK)));
	printf("%u %s\n", philo_id, to_do);//TODO: Print le time
	if (pthread_mutex_unlock(&(data->print)) != 0)
		return (print_err(err_message(ERR_UNLOCK)));
	return (TRUE);
}

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
