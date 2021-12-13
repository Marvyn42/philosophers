/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/12 01:51:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	*test(void *val)
{
	int	*value;

	value = (int*)val;
	printf("You decided to print %d.\n", *value);
	return NULL;
}

int	main(int ac, char **av)
{
	int			*val;
	int			i;
	pthread_t	little_boy[ac - 1];

	if (ac < 2)
	{
		printf("Usage: %s <NUM>.\n", av[0]);
		return (EXIT_SUCCESS);
	}
	i = 1;
	val = (int*)malloc(sizeof(int) * ac - 1);
	while (i < ac)
	{
		if (!val)
		{
			if (i > 1)
				free(val);
			printf("Error malloc.\n");
			return (EXIT_SUCCESS);
		}
		val[i - 1] = atoi(av[i]);
		if (!val[i - 1])
		{
			printf("Atoi didn't appreciate what you gave to it.\n");
			return (EXIT_SUCCESS);
		}
		if (pthread_create(&little_boy[i - 1], NULL, test, &val[i - 1]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(val);
	i = 0;
	while (i < ac - 1)
	{
		if (pthread_join(little_boy[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
		if (i == ac - 1)
			printf("\nAll threads joined.\n");
	}
	return (EXIT_SUCCESS);
}
