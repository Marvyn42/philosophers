/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:24:35 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/31 16:51:33 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	retourne FALSE si STR to INT est plus grand que uint max (4294967295).
*/
t_bool	check_uint_max(const char *str)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - 48);
		if (res >= 429496729 && str[i + 1])
			if (res > 429496729 || (res == 429496729 && str[i + 1] > '5'))
				return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Check sur tout les arguments leur taille.
*/
t_bool	size_max(int ac, char **av)
{
	while (ac)
	{
		if (!check_uint_max(av[ac]))
			return (FALSE);
		ac--;
	}
	return (TRUE);
}

/*
**	Check si str ne contient que des nombres.
*/
t_bool	ft_isdigit(char **arg)
{
	int	i;
	int	j;

	i = 1;
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
	return (TRUE);
}

/*
**	Check sur tout les arguments sont corrects.
*/
t_bool	parsing(int ac, char **av)
{
	if ((ac != 5 && ac != 6) || !ft_isdigit(av) || !size_max(ac - 1, av))
		return (error(ERR_ARG, NONE, NULL));
	return (TRUE);
}
;
