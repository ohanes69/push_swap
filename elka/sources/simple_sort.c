/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:52:31 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/21 15:57:09 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_to_top(t_tab *a, size_t pos, size_t i)
{
	if (pos <= a->size / 2)
	{
		while (pos--)
		{
			rotate(a, "ra");
			a->ra++;
		}
	}
	else
	{
		i = a->size - pos;
		while (i--)
		{
			reverse_rotate(a, "rra");
			a->rra++;
		}
	}
}

static void	find_min(t_tab *a)
{
	size_t	i;
	size_t	pos;
	size_t	min;

	i = 0;
	pos = i;
	min = a->tab[i];
	while (i < a->size)
	{
		if ((int)min > a->tab[i])
		{
			pos = i;
			min = a->tab[i];
		}
		++i;
	}
	min_to_top(a, pos, i);
}

void	simple_sort(t_tab *a, t_tab *b)
{
	while (a->size > 2)
	{
		find_min(a);
		{
			push(a, b, "pb");
			a->pb++;
		}
	}
	if (a->tab[0] > a->tab[1])
	{
		swap(a, "sa");
		a->sa++;
	}
	while (b->size > 0)
	{
		push(b, a, "pa");
		a->pa++;
	}
}
