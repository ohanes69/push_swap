/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:31:20 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/20 18:49:06 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	strategy;
	size_t	is_bench;
	float	metric;

	strategy = 0;
	is_bench = 0;
	if (args[0][0] == '-')
		strategy = ft_strcmp(args[0]);
	if (strategy == 5)
		is_bench = 5;
	if (strategy > 0 && args[1][0] == '-')
		--size;
	if (strategy > 0)
		--size;
	a->size = size;
	b->size = 0;
	strategy = set_tab(strategy, a, args, size);
	metric = compute_disorder(a);
	if (strategy == 0 || strategy == 4)
		strategy = choose_metric(strategy, metric);
	b->tab = malloc(sizeof(int) * size);
	choose_sort(strategy, a, b, size);
	if (is_bench == 5)
		strategy_use(strategy, a, metric);
}
