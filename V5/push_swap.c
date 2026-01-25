/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/25 04:05:09 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

size_t	choose_metric(size_t strategy, float metric)
{
	if (metric < 0.2)
		strategy = 1;
	if (metric >= 0.2 && metric < 0.5)
		strategy = 2;
	if (metric >= 0.5)
		strategy = 3;
	return (strategy);
}

void	choose_sort(size_t s, t_tab *tab, t_strategy *strategy)
{
	if (s == 1)
		simple_sort(tab, strategy);
	else if (s == 2)
		medium_sort(tab, strategy, tab->size_a);
	else if (s == 3)
		complex_sort(tab, strategy, tab->size_a);
}

void	if_bench_flag(size_t s, t_tab *tab, t_strategy *strategy)
{
	float	metric;

	metric = compute_disorder(tab);
	if (s == 0 || s == 4)
		s = choose_metric(s, metric);
	choose_sort(s, tab, strategy);
	strategy_use(s, strategy, metric);
}

void	if_no_bench_flag(size_t s, t_tab *tab, t_strategy *strategy)
{
	float	metric;

	metric = compute_disorder(tab);
	if (s >= 1 && s <= 3)
		choose_sort(s, tab, strategy);
	else if (s == 0 || s == 4)
	{
		s = choose_metric(s, metric);
		choose_sort(s, tab, strategy);
	}
}

size_t	strategy_is_5(t_data *data)
{
	if (data->flag1 == 5)
		return (data->flag2);
	return (data->flag1);
}

void	if_nothing_to_sort(size_t is_bench, size_t s, t_strategy *strategy, float metric)
{
	if (is_bench == 5)
		strategy_use(s, strategy, metric);
	return ;
}

void	push_swap(t_tab *tab, t_strategy *strategy, t_data *data)
{
	size_t	is_bench;
	size_t	s;
	float	metric;

	is_bench = 0;
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
	s = 0;
	if (data->flag2 == 5)
	{
		is_bench = 5;
		s = data->flag1;
	}
	else
		s = data->flag1;
	if (metric == 0)
	{
		if_nothing_to_sort(is_bench, s, strategy, metric);
		return ;
	}
	if (is_bench == 5)
		if_bench_flag(s, tab, strategy);
	else
		if_no_bench_flag(s, tab, strategy);
	free(tab->a);
	free(tab->b);
}
