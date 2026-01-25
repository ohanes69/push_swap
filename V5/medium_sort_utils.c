/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:17:39 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/25 03:28:33 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_chunk(t_tab *tab, size_t low, size_t high)
{
	size_t	i;

	i = 0;
	while (i < tab->size_a)
	{
		if (tab->a[i] >= (int)low && tab->a[i] <= (int)high)
			return (1);
		i++;
	}
	return (0);
}

size_t	get_minimal_distance(size_t size, size_t pos)
{
	size_t	dist_top;
	size_t	dist_bot;

	dist_top = pos;
	dist_bot = size - pos;
	if (dist_bot < dist_top)
		return (dist_bot);
	return (dist_top);
}

size_t	find_range_chunk(size_t n)
{
	size_t	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

size_t	find_numbers_chunks(size_t tab_size, size_t chunk_range)
{
	size_t	nb_chunks;

	nb_chunks = (tab_size + chunk_range - 1) / chunk_range;
	return (nb_chunks);
}

size_t	find_high_chunk(size_t chunk_pos, size_t chunk_range, size_t tab_size)
{
	size_t	low;
	size_t	high;

	low = chunk_pos * chunk_range;
	high = low + chunk_range - 1;
	if (high >= tab_size)
		high = tab_size - 1;
	return (high);
}
