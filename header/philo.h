/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:49 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/07 19:05:24 by mamaquig         ###   ########.fr       */
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
# include <sys/time.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE
}			t_bool;

typedef enum e_free
{
	NONE = 0,
	LIST,
	MUTEX,
	FORK,
	JOIN,
	ALL,
}			t_free;

typedef enum e_error
{
	ERR_ARG = 0,
	ERR_MALLOC,
	ERR_MUTEX,
	ERR_DESTROY,
	ERR_LIST,
	ERR_JOIN,
	ERR_LOCK,
	ERR_UNLOCK,
	ERR_THREAD,
}			t_error;

typedef struct s_data
{
	unsigned int	philo_set;
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_meal_must_eat;
	t_bool			stop;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
}			t_data;

typedef struct s_thread	t_thread;
typedef struct s_thread
{
	unsigned int	id;
	pthread_t		philo;
	t_data			*data;
	pthread_mutex_t	rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	plock;
	unsigned int	nb_meal;
	unsigned int	last_meal;
	t_bool			is_dead;
	t_thread		*next;
}			t_thread;

/*
**	conditions.c
*/
t_bool			stop_simulation(t_thread *thread);
t_bool			is_died(t_thread *thread);
t_bool			still_running(t_data *data);
t_bool			not_satiated(t_thread *thread);
t_bool			condition_running(t_thread *thread);

/*
**	destroy.c
*/
void			free_list(t_thread **thread);
t_bool			join_thread(t_thread **thread);
t_bool			fork_destroy(t_thread **thread);
t_bool			mutex_destroy(t_thread **thread);
t_bool			free_data(t_free free_code, t_thread **thread);

/*
**	error.c
*/
t_bool			print_err(char *str);
char			*err_message(t_error err_code);
t_bool			error(t_error err_code, t_free free_code, t_thread **thread);

/*
**	init.c
*/
t_bool			init_fork(t_thread **thread);
t_bool			init_mutex(t_thread **thread, t_data *data);
t_bool			create_philo(unsigned int nb_philo, t_thread **thread,
					t_data *data);
void			init_data(t_data *data, int ac, char **av);
t_bool			initialisation(t_thread **thread, t_data *data, char **av,
					int ac);

/*
**	list.c
*/
t_thread		*ft_create_elem(t_data *data, unsigned int id);
t_bool			ft_list_push_back(t_thread **begin_list, t_data *data,
					unsigned int id);

/*
**	parse.c
*/
t_bool			check_uint_max(const char *str);
t_bool			size_max(int ac, char **av);
t_bool			ft_isdigit(char **arg);
t_bool			parsing(int ac, char **av);

/*
**	routine.c
*/
t_bool			all_thread_set(t_data *data);
void			*philo_routine(void *data);

/*
**	set_time.c
*/
unsigned int	set_time(t_data *data);

/*
**	to_do.c
*/
t_bool			do_think(t_thread *thread);
t_bool			do_eat(t_thread *thread);
t_bool			do_sleep(t_thread *thread);

/*
**	utils.c
*/
void			ft_usleep(t_data *data, unsigned int us);
t_bool			print_mess(t_data *data, unsigned int philo_id, char *to_do);
unsigned int	ft_atoi(const char *str);

#endif
