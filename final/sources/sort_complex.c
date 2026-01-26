/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:27 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/26 11:46:16 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	radix(t_tab *tab, t_move *move, size_t size, size_t c_bits)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((tab->a[0] >> c_bits & 1) == 0)
		{
			push_b(tab);
			move->pb++;
		}
		else
		{
			rotate_a(tab);
			move->ra++;
		}
		++i;
	}
	while (tab->size_b != 0)
	{
		push_a(tab);
		move->pa++;
	}
}

void	complex_sort(t_tab *tab, t_move *move, size_t size)
{
	size_t	max_bits;
	size_t	current_bits;

	current_bits = 0;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	while (current_bits < max_bits)
	{
		radix(tab, move, size, current_bits);
		++current_bits;
	}
}
