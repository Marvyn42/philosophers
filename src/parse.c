/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:24:35 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/23 18:38:06 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Check si les arguments sont plus grand que unsigned int max (4294967295).
*/
t_bool	size_max(int ac, char **av)
{
	t_bool	ret;

	ret = 1;
	while (ac)
	{
		ft_atoi(av[ac], &ret);
		if (!ret)
			return (FALSE); //TODO: code err
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
				return (FALSE); //TODO: code err
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
**	Check sur tout les arguments sont corrects.
*/
t_bool	parse_data(int ac, char **av)
{
	t_bool	ret;

	if (!ft_isdigit(av) || (ac != 5 && ac != 6) || !size_max(ac - 1, av))
	{//print err code ???
		printf("Usage:\n%s <NUM1> <NUM2> <NUM3> <NUM4> (optionnal)<NUM5>.\n\nN\
UM can only be a positive integer between 0 and 4294967295, and contain nothin\
g else than a positive digit.\n", av[0]);
		return (FALSE);//TODO: code err ???
	}
	return (TRUE);
}
;
