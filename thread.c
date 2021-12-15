/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:07:54 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/15 18:23:01 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"


int		fct_mort_philo()
{
	//set 3 value: -1 philo mort, 0 les philo ont assez mangés, 1 rien a changé
}

char	init_data(t_data *data, unsigned int **arg, int ac)
{
	data->number_of_philosophers = arg[0];
	data->time_to_die = arg[1];
	data->time_to_eat = arg[2];
	data->time_to_sleep = arg[3];
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = arg[4];
	if (pthread_mutex_init(&(data->lock), NULL))
	{
		printf("Error init mutex");
		return (FALSE);
	}
}

char	create_philo(int nb_of_philo, unsigned int *arg, t_thread *thread, int ac)
{
	int			i;
	t_thread	*tmp;
	t_data		data;

	if (!init_data(&data, arg, ac))
		return (FALSE);
	i = 0;
	while (i < nb_of_philo)
	{
		thread = (t_thread*)malloc(sizeof(t_thread));
		if (!thread)
			return (NULL);
		if (!i)
			tmp = thread;
		thread->id = i + 1;
		thread->data = data;
		thread = thread->next;
	}
	thread = tmp;
	return (TRUE);
}

char	philo_hungry_or_alive()
{
	//set une data pour savoir si on doit stop ou non
	//faire un tour de liste pour check cette data
}

char	set_data()
{
	if ((ac != 5 && ac != 6) || !ft_isdigit(av, &tab_arg))
	{
		printf("Usage:\n%s <NUM1> <NUM2> <NUM3> <NUM4> (optionnal)<NUM5>.\nNUM can only be a positive integer between 0 and 2147483647, and contain nothing else than a digit.\n", av[0]);
		return (FALSE);
	}
	if (!create_philo(ft_atoi(av[1]), tab_arg, thread, ac))
		return (FALSE);
}

int	main(int ac, char **av)
{
	int				i;
	int				ret;
	unsigned int	*tab_arg;
	t_thread		*thread;
	
	///////////////////////////////////////////////////////////////////////////
	if (!set_data())
		return (EXIT_FAILURE);
	///////////////////////////////////////////////////////////////////////////
	ret = 1;
	i = 0;
//---------------------------------------------------------------------------//
	while (ret)
	{
		if (i < thread->data.number_of_philosophers)
		{
			if (pthread_create(&(thread->philo), NULL, philo_routine, thread) != 0)
				return (EXIT_FAILURE);
			if (i != thread->data.number_of_philosophers - 1)
				thread = thread->next;
			i++;
		}
		//faire la boucle ici de alive ?
		ret = philo_hungry_or_alive(thread);
		if (ret = -1)
			return (fct_mort_philo(thread));
	}
//---------------------------------------------------------------------------//
	i = 0;
	while (i < thread->data.number_of_philosophers)
	{
		if (pthread_join(&(thread->philo), NULL) != 0)
			return (EXIT_FAILURE);
		if (i != thread->data.number_of_philosophers - 1)
			thread = thread->next;
		i++;
	}
	// secur le mutex destroy ??
	pthread_mutex_destroy(&(thread->data.lock));
	ft_free(&thread);
	return (EXIT_SUCCESS);
}

//finir de set_data.
//m'attaquer à la routine
