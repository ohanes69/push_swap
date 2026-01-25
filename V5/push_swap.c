/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/25 17:08:53 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	choose_metric(t_data *data, float metric)
{
	if (metric < 0.2)
		data->flag1 = 1;
	if (metric >= 0.2 && metric < 0.5)
		data->flag1 = 2;
	if (metric >= 0.5)
		data->flag1 = 3;
}

void	choose_sort(t_data *data, t_tab *tab, t_strategy *strategy)
{
	if (data->flag1 == 1)
		simple_sort(tab, strategy);
	else if (data->flag1 == 2)
		medium_sort(tab, strategy, tab->size_a);
	else if (data->flag1 == 3)
		complex_sort(tab, strategy, tab->size_a);
}

void	sort_tab(t_data *data, t_tab *tab, t_strategy *strategy, float metric)
{
	if (metric == 0)
	{
		if (data->flag2 == 5)
			strategy_use(data, strategy, metric);
		return ;
	}
	if (data->flag1 >= 1 && data->flag1 <= 3)
		choose_sort(data, tab, strategy);
	else if (data->flag1 == 0 || data->flag1 == 4)
	{
		choose_metric(data, metric);
		choose_sort(data, tab, strategy);
	}
	if (data->flag2 == 5)
		strategy_use(data, strategy, metric);
}

void	push_swap(t_tab *tab, t_strategy *strategy, t_data *data)
{
	float	metric;

	tab->size_a = data->size - data->nb_flag;
	tab->size_b = 0;
	tab->b = malloc(sizeof(int) * (tab->size_a));
	if (!tab->b)
	{
		free(tab->a);
		free(tab->b);
		return ;
	}
	indexing(tab);
	metric = compute_disorder(tab);
	sort_tab(data, tab, strategy, metric);
	free(tab->a);
	free(tab->b);
}
