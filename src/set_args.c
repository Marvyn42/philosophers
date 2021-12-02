/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:01:47 by mamaquig          #+#    #+#             */
/*   Updated: 2021/10/21 02:32:47 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	set_args(char *buf, int *arg)
{
	char tmp;

	tmp = ft_is_num(buf);
	if (tmp == 0)
		return (0);
	else if (tmp == -1)
		*arg = 0;
	else
		*arg = ft_atoi(buf);
	return (1);
}

char	ask_args(t_arg *arg)
{
	char	buf[256];

	write(1, "Number of philosophers ?\n", 25);
	read(STDIN_FILENO, buf, 256);
	if (!set_args(buf, &(arg->number_of_philo)))
		return (0);
	write(1, "\nTime to die: is in milliseconds ?\n", 35);
	read(STDIN_FILENO, buf, 256);
	if (!set_args(buf, &(arg->time_to_die)))
		return (0);
	write(1, "\nTime to eat ?\n", 15);
	read(STDIN_FILENO, buf, 256);
	if (!set_args(buf, &(arg->time_to_eat)))
		return (0);
	write(1, "\nTime to sleep ?\n", 17);
	read(STDIN_FILENO, buf, 256);
	if (!set_args(buf, &(arg->time_to_sleep)))
		return (0);
	write(1, "\nNumber of times each philosopher must eat ?\n", 45);
	read(STDIN_FILENO, buf, 256);
	if (!set_args(buf, &(arg->number_of_times_each_philosopher_must_eat)))
		return (0);
	write(1, "\n", 1);
	return (1);
}
