/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/10 18:39:07 by mamaquig         ###   ########.fr       */
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
	int			val;
	pthread_t	little_boy;

	if (ac < 2)
	{
		printf("Usage: %s <NUM>.\n", av[0]);
		return (EXIT_SUCCESS);
	}
	val = atoi(av[1]);
	if (!val)
	{
		printf("Atoi didn't appreciate what you gave to it.\n");
		return (EXIT_SUCCESS);
	}
	while (i < )
	if ((pthread_create(&little_boy, NULL, test, &val)) != 0)
		return (EXIT_FAILURE);
	if (pthread_join(little_boy, NULL) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
