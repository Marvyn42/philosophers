/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:18:10 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/28 14:25:29 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
