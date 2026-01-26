/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 14:04:10 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static float	compute_disorder(t_tab *tab)
{
	size_t	i;
	size_t	j;
	size_t	total_pairs;
	size_t	mistakes;
	float	metric;

	total_pairs = 0;
	mistakes = 0;
	i = 0;
	if (tab->size_a == 1)
		return (0);
	while (i < tab->size_a - 1)
	{
		j = i + 1;
		while (j < tab->size_a)
		{
			++total_pairs;
			if (tab->a[i] > tab->a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	metric = ((float)mistakes / total_pairs);
	return (metric);
}

static void	strategy_select(t_data *data, t_tab *tab, t_move *mv, float metric)
{
	if (metric == 0)
	{
		if (data->flag2 == 5)
			bench(data, mv, metric);
		return ;
	}
	if (data->flag1 == 1)
		simple_sort(tab, mv);
	else if (data->flag1 == 2)
		medium_sort(tab, mv, tab->size_a);
	else if (data->flag1 == 3)
		complex_sort(tab, mv, tab->size_a);
	else
	{
		if (metric < 0.2)
			simple_sort(tab, mv);
		if (metric >= 0.2 && metric < 0.5)
			medium_sort(tab, mv, tab->size_a);
		if (metric >= 0.5)
			complex_sort(tab, mv, tab->size_a);
	}
	if (data->flag2 == 5)
		bench(data, mv, metric);
}

bool	push_swap(t_tab *tab, t_move *move, t_data *data)
{
	float	metric;

	tab->size_a = data->size;
	tab->size_b = 0;
	tab->b = malloc(sizeof(int) * (tab->size_a));
	if (!tab->b)
	{
		free(tab->a);
		free(tab->b);
		return (false);
	}
	metric = compute_disorder(tab);
	strategy_select(data, tab, move, metric);
	free(tab->a);
	free(tab->b);
	return (true);
}
