/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:26:59 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/01 23:08:07 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_err(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	return (FALSE);
}

char	*err_message(t_error err_code)
{
	if (err_code == ERR_ARG)
	{
		return("Usage:\n./philo <NUM1> <NUM2> <NUM3> <NUM4> (optionnal)<NUM5>.\
\n\nNUM can only be a positive integer between 0 and 4294967295, and contain\
nothing else than a positive digit.\n");
	}
	if (err_code == ERR_DESTROY)
		return ("Error, can not destroy mutex.\n");
	if (err_code == ERR_JOIN)
		return ("Error, can not join threads.\n");
	if (err_code == ERR_MALLOC)
		return ("Error, can not malloc.\n");
	if (err_code == ERR_MUTEX)
		return ("Error, can not create mutex.\n");
	if (err_code == ERR_LIST)
		return ("Error during list creation.\n");
	if (err_code == ERR_LOCK)
		return ("Error, can not lock a mutex.\n");
	if (err_code == ERR_UNLOCK)
		return ("Error, can not unlock a mutex.\n");
	if (err_code == ERR_THREAD)
		return ("Error, can not create a thread.\n");
	return ("Unknow error\n");
}

t_bool	error(t_error err_code, t_free free_code, t_thread **thread)
{
	//set data->stop, trouver la condition pour le faire (philo_set ?)
	print_err(err_message(err_code));
	if (free_code != NONE)
		free_data(free_code, thread);
	return (FALSE);
}
