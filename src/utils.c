/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:18:10 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/20 18:34:44 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Check sur tout les arguments si ils ne contiennent que des entiers entre 0 et 2147483647
*/
t_bool	ft_isdigit(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
			{
				printf("ok si c la je rigole\n");
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
**	Free tout les maillons de ma liste t_thread *thread.
*/

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
			if (res > 429496729 || (res == 429496729 && str[i + 1] >= '5'))
				ret = 0;
		i++;
	}
	return (res);
}
