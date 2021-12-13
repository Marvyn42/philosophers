/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:34:46 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/08 16:10:47 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_arg
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}				t_arg;

/*
**	SET_ARGS
*/
char	set_args(char *buf, int *arg);
char	ask_args(t_arg *arg);

/*
**	UTILS
*/
int		ft_atoi(const char *str);
int		ft_is_num(char *str);

#endif
