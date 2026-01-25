/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:02:56 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/25 17:13:00 by samarkar         ###   ########lyon.fr   */
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

	if (ac <= 2) // retourner error si argv[1] est --simp ?
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
	push_swap(tab, strategy, data);
	free_all(tab, strategy, data);
}
