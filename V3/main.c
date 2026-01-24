/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:02:56 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/24 03:07:04 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_strategy *stack)
{
	stack->sa = 0;
	stack->sb = 0;
	stack->ss = 0;
	stack->pa = 0;
	stack->pb = 0;
	stack->ra = 0;
	stack->rb = 0;
	stack->rr = 0;
	stack->rra = 0;
	stack->rrb = 0;
	stack->rrr = 0;
}

static void	free_all(t_tab *tab, t_strategy *strategy, t_data *data)
{
	if (tab)
		free(tab);
	if (strategy)
		free(strategy);
	if (data)
		free(data);
}

int	main(int ac, char **av)
{
	t_tab		*tab;
	t_strategy 	*strategy;
	t_data 		*data;

	if (ac <= 2)
		return (0);
	tab = malloc(sizeof(t_tab));
	strategy = malloc(sizeof(t_strategy));
	data = malloc(sizeof(t_data));
	if (!tab || !strategy || !data)
	{
		free_all(tab, strategy, data);
		return (1);
	}
	init_stack(strategy);
	tab = parsing(ac, av, tab, data);
	size_t i = 0;
	while (i < ac - 1)
	{
		printf("%d", tab->a[i]);
		++i;
	}
	
	// push_swap(args, a, b, size);
	// free_all(tab, strategy, data);
}
