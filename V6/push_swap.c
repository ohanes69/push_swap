/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 10:19:26 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	strategy_select(t_data *data, t_tab *tab, t_strategy *strategy, float metric)
{
	if (metric == 0)
	{
		if (data->flag2 == 5)
			strategy_use(data, strategy, metric);
		return ;
	}
	if (data->flag1 == 1)
		simple_sort(tab, strategy);
	else if (data->flag1 == 2)
		medium_sort(tab, strategy, tab->size_a);
	else if (data->flag1 == 3)
		complex_sort(tab, strategy, tab->size_a);
	else
	{
		if (metric < 0.2)
			simple_sort(tab, strategy);
		if (metric >= 0.2 && metric < 0.5)
			medium_sort(tab, strategy, tab->size_a);
		if (metric >= 0.5)
			complex_sort(tab, strategy, tab->size_a);
	}
	if (data->flag2 == 5)
		strategy_use(data, strategy, metric);
}

bool	push_swap(t_tab *tab, t_strategy *strategy, t_data *data)
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
	strategy_select(data, tab, strategy, metric);
	free(tab->a);
	free(tab->b);
	return (true);
}
