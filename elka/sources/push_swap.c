/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:31:20 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/21 18:57:41 by lucpelle         ###   ########.fr       */
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

void	choose_sort(size_t strategy, t_tab *a, t_tab *b, size_t size)
{
	if (strategy == 1)
		simple_sort(a, b);
	else if (strategy == 2)
		medium_sort(a, b, size);
	else if (strategy == 3)
		complex_sort(a, b, size);
}

void	if_nothing_to_sort(float metric, size_t is_bench, size_t strategy, t_tab *a)
{
	if (metric == 0.000000 && is_bench != 5)
		return ;
	else if (metric == 0.000000 && is_bench == 5)
	{
		strategy_use(strategy, a, metric);
		return ;
	}
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	strategy;
	size_t	is_bench;
	float	metric;

	strategy = 0;
	is_bench = 0;
	if (args[0][0] == '-' && args[0][1] == '-')
	{
		strategy = ft_strcmp(args[0]);
		if (strategy == 0)
		{
			print_error();
			return ;
		}
		else
			size--;
	}
	if (args[1][0] == '-' && args[1][1] == '-')
	{
		is_bench = ft_strcmp(args[1]);
		if (is_bench == 0 || is_bench == strategy)
		{
			print_error();
			return ;
		}
		else
			size--;
	}
	a->tab = malloc(sizeof(int) * size);
	b->tab = malloc(sizeof(int) * size);
	a->size = size;
	b->size = 0;
	if (strategy > is_bench)
	{
		int	tmp;
		tmp = strategy;
		strategy = is_bench;
		is_bench = tmp;
	}
	set_tab(is_bench, strategy, a, args, size);
	metric = compute_disorder(a);
	if (metric == 0.000000)
	{
		if_nothing_to_sort(metric, is_bench, strategy, a);
		return ;
	}
	if (strategy == 0 || strategy == 4)
		strategy = choose_metric(strategy, metric);
	choose_sort(strategy, a, b, size);
	if (is_bench == 5)
		strategy_use(strategy, a, metric);
}
