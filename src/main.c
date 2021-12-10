/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:41:41 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/10 17:43:13 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	créer une var pthread_t xxx;
	créer le thread avec la var pthread_t: pthread_create(&xxx, &attr, ptr_sur_fct, arg);

	le programme peut se terminer avant le thread, on va donc l'attendre avec:
	pthread_join(xxx, NULL);
*/

/*
	int pthread_create (pthread_t * thread, pthread_attr_t * attr, void * (* start_routine) (void *), void * arg);
		Le type pthread_t est un type opaque, sa valeur réelle dépend de l'implémentation (sur Linux il s'agit en générale du type unsigned long).
	Ce type correspond à l'identifiant du thread qui sera créé, tout comme les processus ont leur propre identifiant.

		Le type pthread_attr_t est un autre type opaque permettant de définir des attributs spécifiques pour chaque thread, mais cela dépasse le cadre
	de ce tutoriel. Il faut simplement savoir que l'on peut changer le comportement de la gestion des threads par exemple, les régler pour qu'ils tournent
	sur un système temps réel ! En général on se contente des attributs par défaut donc en mettant cet argument à NULL.

		Chaque thread dispose d'une fonction à exécuter, c'est en même temps sa raison de vivre… Cet argument permet de transmettre un pointeur sur la fonction
	qu'il devra exécuter.

	Ce dernier argument représente un argument que l'on peut passer à la fonction que le thread doit exécuter.
*/

void	test_thread(void)
{
}


void	print_list(t_arg arg)
{
	printf("number_of_philo = %d\n", arg.number_of_philo);
	printf("time_to_die = %d\n", arg.time_to_die);
	printf("time_to_eat = %d\n", arg.time_to_eat);
	printf("time_to_sleep = %d\n", arg.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat = %d\n", arg.number_of_times_each_philosopher_must_eat);
}

int	main(void)
{
	t_arg	arg;

	if (!ask_args(&arg))
	{
		write(1, "Please, write positive interger only.\n", 38);
		return (EXIT_SUCCESS);
	}
	print_list(arg);
	test_thread();
	return (EXIT_SUCCESS);
}

//pour gérer le temps ?= int usleep(useconds_t usec);

//usleep into (write(1, str[i], 1)), i++ pour écrire en direct
//la valeur de temps dans uspeed peut être random pour rendre le rendu plus réaliste (valeur minime)
