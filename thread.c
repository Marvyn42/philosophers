/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/13 08:20:17 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data
{
	int				val;
	int				i;
	char			**arg;
	pthread_mutex_t	lock;
}				t_data;


void	*test(void *data)
{
	t_data	*tmp;

	tmp = data;
	pthread_mutex_lock(&tmp->lock);
	tmp->val = atoi(tmp->arg[tmp->i]);
	printf("You decidedto print %d.\n", tmp->val);
	tmp->i += 1;
	pthread_mutex_unlock(&tmp->lock);
	return NULL;
}

int	main(int ac, char **av)
{
	int			i;
	pthread_t	*little_boy;
	t_data		data;

	data.val = 0;
	data.i = 1;
	data.arg = av;
	if (ac < 2)
	{
		printf("Usage: %s <NUM1 NUM2 NUM3 ...>.\n", av[0]);
		return (EXIT_SUCCESS);
	}
	if (pthread_mutex_init(&data.lock, NULL))
	{
		printf("Error init mutex");
		return (EXIT_FAILURE);
	}
	i = 1;
	little_boy = (pthread_t*)malloc(sizeof(pthread_t) * ac - 1);
	while (i < ac)
	{
		if (pthread_create(&little_boy[i - 1], NULL, test, &data) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		if (pthread_join(little_boy[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	pthread_mutex_destroy(&data.lock);
	free(little_boy);
	return (EXIT_SUCCESS);
}
