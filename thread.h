/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:49 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/15 18:15:55 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1

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

void			*philo_routine(void *data);
char			ft_isdigit(char **arg, int **tab_arg);
void			ft_free(t_thread **thread);
char			int_size(int **tab_arg, char **arg);
unsigned int	ft_atoi(const char *str);

#endif
