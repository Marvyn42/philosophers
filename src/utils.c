/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:18:10 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/23 18:25:13 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_atoi(const char *str, t_bool *ret)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	(void)ret;
	while (str[i])
	{
		res = (res * 10) + (str[i] - 48);
		if (res >= 429496729 && str[i + 1])
			if (res > 429496729 || (res == 429496729 && str[i + 1] > '5'))
			{
				if (ret)
					*ret = 0;
				return (0);
			}
		i++;
	}
	return (res);
}
