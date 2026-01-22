/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:31:20 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/22 16:08:45 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


static void	strategy_selector(float metric, size_t strategy, t_tab *a, t_tab *b, size_t size)
{
	if (strategy == 0 || strategy == 4)
	{
		if (metric < 0.2)
			simple_sort(a, b);
		if (metric >= 0.2 && metric < 0.5)
			medium_sort(a, b, size);
		if (metric >= 0.5)
			complex_sort(a, b, size);
	}
	else if (strategy == 1)
		simple_sort(a, b);
	else if (strategy == 2)
		medium_sort(a, b, size);
	else if (strategy == 3)
		complex_sort(a, b, size);
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
	indexing(a, size);
	is_duplicate(a, size);
}

void	init_tab(t_tab *a, t_tab *b, size_t size)
{
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
	metric = compute_disorder(a);
	i = 0;
	if (metric == 0.000000 && is_bench == 5)
	{
		strategy_use(strategy, a, metric);
		free(a->tab);
		free(b->tab);
		return ;
	}
	strategy_selector(metric, strategy, a, b, size);
	if (is_bench == 5)
		strategy_use(strategy, a, metric);
	free(a->tab);
	free(b->tab);
}
