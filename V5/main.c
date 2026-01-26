/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:02:56 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 11:46:16 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_stack(t_move *stack)
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

static void	free_all(t_tab *tab, t_move *move, t_data *data)
{
	if (tab)
		free(tab);
	if (move)
		free(move);
	if (data)
		free(data);
}

int	main(int ac, char **av)
{
	t_tab		*tab;
	t_move	*move;
	t_data		*data;

	if (ac <= 2)
		return (0);
	tab = malloc(sizeof(t_tab));
	move = malloc(sizeof(t_move));
	data = malloc(sizeof(t_data));
	if (!tab || !move || !data)
	{
		free_all(tab, move, data);
		return (1);
	}
	init_stack(move);
	tab = parsing(ac, av, tab, data);
	push_swap(tab, move, data);
	free_all(tab, move, data);
}
