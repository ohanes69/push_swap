/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:18:46 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 11:46:16 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	rotate_to_top(t_tab *tab, t_move *move, size_t pos)
{
	size_t	dist_top;
	size_t	dist_bot;
	size_t	i;

	dist_top = pos;
	dist_bot = tab->size_a - pos;
	i = 0;
	if (dist_top <= dist_bot)
	{
		while (i < dist_top)
		{
			rotate_a(tab);
			move->ra++;
			i++;
		}
	}
	else
	{
		while (i < dist_bot)
		{
			reverse_rotate_a(tab);
			move->rra++;
			i++;
		}
	}
}

static size_t	find_closest_in_chunk(t_tab *tab, size_t low, size_t high)
{
	size_t	i;
	size_t	min_distance;
	size_t	best_pos;
	size_t	current_dist;

	min_distance = tab->size_a;
	best_pos = tab->size_a;
	i = 0;
	while (i < tab->size_a)
	{
		if ((size_t)tab->a[i] >= low && (size_t)tab->a[i] <= high)
		{
			current_dist = get_minimal_distance(tab->size_a, i);
			if (current_dist < min_distance)
			{
				min_distance = current_dist;
				best_pos = i;
			}
		}
		i++;
	}
	return (best_pos);
}

static void	rotate_push_elem(t_tab *tab, t_move *s, size_t low, size_t high)
{
	size_t	pos;

	pos = find_closest_in_chunk(tab, low, high);
	if (pos == tab->size_a)
		return ;
	rotate_to_top(tab, s, pos);
	push_b(tab);
	s->pb++;
}

static void	push_chunk_to_b(t_tab *tab, t_move *s, size_t low, size_t high)
{
	while (is_in_chunk(tab, low, high) == 1)
	{
		rotate_push_elem(tab, s, low, high);
		if (tab->b[0] <= (int)((low + high) / 2))
		{
			rotate_b(tab);
			s->rb++;
		}
	}
}

void	medium_sort(t_tab *tab, t_move *move, size_t size)
{
	size_t	chunk_range;
	size_t	nb_chunks;
	size_t	chunk_pos;
	size_t	low;
	size_t	high;

	chunk_range = find_range_chunk(size);
	nb_chunks = find_numbers_chunks(size, chunk_range);
	chunk_pos = 0;
	while (chunk_pos < nb_chunks)
	{
		low = chunk_pos * chunk_range;
		high = find_high_chunk(chunk_pos, chunk_range, size);
		push_chunk_to_b(tab, move, low, high);
		chunk_pos++;
	}
	push_to_a(tab, move);
}
