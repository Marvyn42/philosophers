/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:18:10 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/18 19:22:24 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	int_size(int *tab_arg, char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		tab_arg[i] = ft_atoi(arg[i]);
		if (tab_arg[i] > UINT_MAX)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Check sur tout les arguments si ils ne contiennent que des entiers entre 0 et 2147483647
*/
t_bool	ft_isdigit(char **arg, int *tab_arg)
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
				return (FALSE);
			j++;
		}
		i++;
	}
	if (!int_size(tab_arg, arg))
		return (FALSE);
	return (TRUE);
}

/*
**	Free tout les maillons de ma liste t_thread *thread.
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
