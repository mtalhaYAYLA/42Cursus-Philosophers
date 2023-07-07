/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myayla <myayla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:02:39 by myayla            #+#    #+#             */
/*   Updated: 2023/07/06 01:03:51 by myayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_ps(t_table *table)
{
	sem_close(table->is_dying);
	sem_close(table->is_printing);
	sem_close(table->forks);
	sem_unlink("./forks");
	sem_unlink("./printing");
	sem_unlink("./dying");
	free(table->philos);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = parse(ac, av);
	if (table != NULL)
	{
		start_forks(table);
		end_ps(table);
	}
	return (0);
}
