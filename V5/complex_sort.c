/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:27 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/25 17:55:29 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	radix(t_tab *tab, t_strategy *strategy, size_t size, size_t c_bits)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((tab->a[0] >> c_bits & 1) == 0)
		{
			push_b(tab);
			strategy->pb++;
		}
		else
		{
			rotate_a(tab);
			strategy->ra++;
		}
		++i;
	}
	while (tab->size_b != 0)
	{
		push_a(tab);
		strategy->pa++;
	}
}

void	complex_sort(t_tab *tab, t_strategy *strategy, size_t size)
{
	size_t	max_bits;
	size_t	current_bits;

	current_bits = 0;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	while (current_bits < max_bits)
	{
		radix(tab, strategy, size, current_bits);
		++current_bits;
	}
}
