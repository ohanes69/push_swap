/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:42:40 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/24 19:38:39 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top_b(t_tab *tab, t_strategy *strategy, size_t pos)
{
	size_t	dist_top;
	size_t	dist_bot;
	size_t	i;

	dist_top = pos;
	dist_bot = tab->size_b - pos;
	i = 0;
	if (dist_top <= dist_bot)
	{
		while (i < dist_top)
		{
			rotate_b(tab);
			strategy->rb++;
			i++;
		}
	}
	else
	{
		while (i < dist_bot)
		{
			reverse_rotate_b(tab);
			strategy->rrb++;
			i++;
		}
	}
}

static size_t	find_max_pos(t_tab *tab)
{
	int		max;
	size_t	i;

	i = 0;
	max = tab->b[i];
	while (i < tab->size_b - 1)
	{
		if (max < tab->b[i + 1])
			max = tab->b[i + 1];
		i++;
	}
	i = 0;
	while (i < tab->size_b)
	{
		if (tab->b[i] == max)
			return (i);
		i++;
	}
	return (i);
}

void	push_to_a(t_tab *tab, t_strategy *strategy)
{
	size_t	max_b;

	while (tab->size_b > 0)
	{
		max_b = find_max_pos(tab);
		rotate_to_top_b(tab, strategy, max_b);
		push_a(tab);
		strategy->pa++;
	}
}
