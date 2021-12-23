/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:49 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/23 13:36:47 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE
}			t_bool;

typedef enum e_err
{
	unavailable = 0,
	available,
}			t_err;

typedef struct s_data
{
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	number_of_times_each_philosopher_must_eat;
	t_bool			ac_6;
	t_bool			stop;
	pthread_mutex_t	lock;
}			t_data;

typedef struct s_thread	t_thread;
typedef struct s_thread
{
	unsigned int	id;
	pthread_t		philo;
	t_data			*data;
	pthread_mutex_t	rfork;
	pthread_mutex_t	*lfork;
	unsigned int	nb_meal;
	t_bool			is_dead;
	t_thread		*next;
}			t_thread;

/*
**	memory_allocation.c
*/
void			*ft_calloc(size_t count, size_t size);
void			ft_free(t_thread **thread);
t_bool			close_data(t_thread **thread, t_bool tmp);

/*
**	utils.c
*/
unsigned int	ft_atoi(const char *str, t_bool *ret);
t_bool			ft_isdigit(char **arg);

/*
**	data_struct.c
*/
t_bool			create_philo(unsigned int nb_philo, t_thread **tmp, int ac,
					char **av);
t_bool			init_data(t_data *data, int ac, char **av);
t_bool			set_data(int ac, char **av, t_thread **thread);

/*
**	list.c
*/
t_thread		*ft_create_elem(t_data *data, unsigned int id);
void			ft_list_push_back(t_thread **begin_list, t_data *data,
					unsigned int id);

/*
**	routine.c
*/
void			*philo_routine(void *data);

//TODO:REMOVE
void	printdata(t_thread *thread);

#endif
