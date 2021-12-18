/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:49 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/18 19:30:31 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: CHECK NORME

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
#include <limits.h>
# include <stdlib.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE
}			t_bool;

typedef enum e_fork
{
	unavailable = 0,
	available,
}			t_fork;

typedef struct s_data
{
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	lock;
	t_fork			fork;
}			t_data;

typedef struct s_thread
{
	unsigned int	id;
	pthread_t		philo;
	t_data			data;
	t_thread		*next;
}			t_thread;

/*
**	memory_allocation.c
*/
void			*ft_calloc(size_t count, size_t size);
void			ft_free(t_thread *thread);
t_bool			close_data(t_thread *thread);

/*
**	utils.c
*/
unsigned int	ft_atoi(const char *str);
t_bool			int_size(int *tab_arg, char **arg);
t_bool			ft_isdigit(char **arg, int *tab_arg);

/*
**	data_struct.c
*/
t_bool			create_philo(int nb_philo, unsigned int *arg, t_thread *thread,
					int ac);
t_bool			init_data(t_data *data, unsigned int *arg, int ac);
t_bool			set_data(int ac, char **av, t_thread *thread);

/*
**	routine.c
*/
void			*philo_routine(void *data);

#endif
