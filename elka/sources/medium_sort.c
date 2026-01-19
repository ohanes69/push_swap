/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:18:46 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/16 19:50:35 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_tab *a, size_t pos)
{
	size_t	dist_top;
	size_t	dist_bot;
	size_t	i;

	dist_top = pos;
	dist_bot = a->size - pos;
	i = 0;
	if (dist_top <= dist_bot)
	{
		while (i < dist_top)
		{
			rotate(a, "ra");
			i++;
		}
	}
	else
	{
		while (i < dist_bot)
		{
			reverse_rotate(a, "rra");
			i++;
		}
	}
}

static size_t	find_closest_in_chunk(t_tab *a, size_t low, size_t high)
{
	size_t	i;
	size_t	min_distance;
	size_t	best_pos;
	size_t	current_dist;

	min_distance = a->size;
	best_pos = a->size;
	i = 0;
	while (i < a->size)
	{
		if ((size_t)a->tab[i] >= low && (size_t)a->tab[i] <= high)
		{
			current_dist = get_minimal_distance(a, i);
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

static void	rotate_push_element(t_tab *a, t_tab *b, size_t low, size_t high)
{
	size_t	pos;

	pos = find_closest_in_chunk(a, low, high);
	if (pos == a->size)
		return ;
	rotate_to_top(a, pos);
	push(a, b, "pb");
}

static void	push_chunk_to_b(t_tab *a, t_tab *b, size_t low, size_t high)
{
	while (is_in_chunk(a, low, high) == 1)
	{
		rotate_push_element(a, b, low, high);
		if (b->tab[0] <= (int)((low + high) / 2))
			rotate(b, "rb");
	}
}

void	medium_sort(t_tab *a, t_tab *b, size_t size)
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
		push_chunk_to_b(a, b, low, high);
		chunk_pos++;
	}
	push_to_a(a, b);
}
