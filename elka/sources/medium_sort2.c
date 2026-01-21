/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:42:40 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/19 17:49:48 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top_b(t_tab *a, t_tab *b, size_t pos)
{
	size_t	dist_top;
	size_t	dist_bot;
	size_t	i;

	dist_top = pos;
	dist_bot = b->size - pos;
	i = 0;
	if (dist_top <= dist_bot)
	{
		while (i < dist_top)
		{
			rotate(b, "rb");
			a->rb++;
			i++;
		}
	}
	else
	{
		while (i < dist_bot)
		{
			reverse_rotate(b, "rrb");
			a->rrb++;
			i++;
		}
	}
}

static size_t	find_max_pos(t_tab *b)
{
	size_t	max;
	size_t	i;

	i = 0;
	max = b->tab[i];
	while (i < b->size - 1)
	{
		if (max < (size_t)b->tab[i + 1])
			max = (size_t)b->tab[i + 1];
		i++;
	}
	i = 0;
	while (i < b->size)
	{
		if ((size_t)b->tab[i] == max)
			return (i);
		i++;
	}
	return (i);
}

void	push_to_a(t_tab *a, t_tab *b)
{
	size_t	max_b;

	while (b->size > 0)
	{
		max_b = find_max_pos(b);
		rotate_to_top_b(a, b, max_b);
		push(b, a, "pa");
		a->pa++;
	}
}
