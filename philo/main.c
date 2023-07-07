/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myayla <myayla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:05:57 by myayla            #+#    #+#             */
/*   Updated: 2023/07/06 01:06:00 by myayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ending_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philos)
	{
		if (table->number_of_philos == 1)
			pthread_detach(table->philos[i].thread);
		pthread_join(table->philos[i].thread, NULL);
	}
	pthread_mutex_destroy(&table->is_dying);
	pthread_mutex_destroy(&table->is_printing);
	i = -1;
	while (++i < table->number_of_philos)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
	free(table->philos);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = parse(ac, av);
	if (table != NULL)
	{
		creating_threads(table);
		ending_threads(table);
	}
	return (0);
}
