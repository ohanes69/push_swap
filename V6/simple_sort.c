/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:52:31 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/24 17:55:53 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_to_top(t_tab *tab, t_strategy *strategy, size_t pos, size_t i)
{
	if (pos <= tab->size_a / 2)
	{
		while (pos--)
		{
			rotate_a(tab);
			strategy->ra++;
		}
	}
	else
	{
		i = tab->size_a - pos;
		while (i--)
		{
			reverse_rotate_a(tab);
			strategy->rra++;
		}
	}
}

static void	find_min(t_tab *tab, t_strategy *strategy)
{
	size_t	i;
	size_t	pos;
	size_t	min;

	i = 0;
	pos = i;
	min = tab->a[i];
	while (i < tab->size_a)
	{
		if ((int)min > tab->a[i])
		{
			pos = i;
			min = tab->a[i];
		}
		++i;
	}
	min_to_top(tab, strategy, pos, i);
}

void	simple_sort(t_tab *tab, t_strategy *strategy)
{
	while (tab->size_a > 2)
	{
		find_min(tab, strategy);
		push_b(tab);
		strategy->pb++;
	}
	if (tab->a[0] > tab->a[1])
	{
		swap(tab, 'a');
		strategy->sa++;
	}
	while (tab->size_b > 0)
	{
		push_a(tab);
		strategy->pa++;
	}
}
