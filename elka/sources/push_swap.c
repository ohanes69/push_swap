/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:31:20 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/22 14:35:21 by lucpelle         ###   ########.fr       */
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
	if (is_bench != 5)
		return ;
	else if (is_bench == 5)
	{
		strategy_use(strategy, a, metric);
		return ;
	}
}
static void	set_tab(size_t i, t_tab *a, char **args, size_t size)
{
	size_t	j;

	j = 0;
	while (j < size)
	{
		a->tab[j] = is_valid_int(args[i + j]);
		++j;
	}
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	strategy;
	size_t	is_bench;
	size_t	i;
	float	metric;

	strategy = 0;
	is_bench = 0;
	i = 0;
	
	if (args[0][0] == '-' && args[0][1] == '-')
	{
		strategy = ft_strcmp(args[0]);
		if (strategy == 0)
			return ;
		size--;
		i++;
	}
	if (args[1][0] == '-' && args[1][1] == '-')
	{
		is_bench = ft_strcmp(args[1]);
		if (strategy == 0)
			return ;
		size--;
		i++;
	}
	if (strategy == is_bench && strategy != 0)
		return ;
	if (strategy == 5)
	{
		int	tmp;
		tmp = strategy;
		strategy = is_bench;
		is_bench = tmp;
	}
	a->size = size;
	a->tab = malloc(sizeof(int) * size);
	b->size = 0;
	b->tab = malloc(sizeof(int) * size);
	
	if (!a->tab || !b->tab)
	{
		free(a->tab);
		free(b->tab);
		return ;
	}
	set_tab(i, a, args, size);
	metric = compute_disorder(a);
	__builtin_printf("%f\n", metric);
	i = 0;
	medium_sort(a, b, size);
	while (size > 0)
	{
		__builtin_printf("%d\n", a->tab[i]);
		i++;
		size--;
	}
	// if (metric == 0.000000)
	// {
	// 	if_nothing_to_sort(metric, is_bench, strategy, a);
	// 	return ;
	// }
	// if (strategy == 0 || strategy == 4)
	// 	strategy = choose_metric(strategy, metric);
	// choose_sort(strategy, a, b, size);
	// if (is_bench == 5)
	// 	strategy_use(strategy, a, metric);
	free(a->tab);
	free(b->tab);
}
