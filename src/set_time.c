/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:28:22 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/04 01:45:06 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Renvoi l'horodatage.
*/
unsigned int	set_time(void)
{
	struct timeval		tv;
	static unsigned int	start = 0;

	gettimeofday(&tv, NULL);
	if (!start)
		start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}
