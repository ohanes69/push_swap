/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:27 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/21 15:56:28 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	complex_sort(t_tab *a, t_tab *b, size_t size)
{
	size_t	max_bits;
	size_t	current_bits;
	size_t	i;

	current_bits = 0;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	while (current_bits < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((a->tab[0] >> current_bits & 1) == 0)
			{
				push(a, b, "pb");
				a->pb++;
			}
			else
			{
				rotate(a, "ra");
				a->ra++;
			}
			++i;
		}
		while (b->size != 0)
		{
			push(b, a, "pa");
			a->pa++;
		}
		++current_bits;
	}
}
