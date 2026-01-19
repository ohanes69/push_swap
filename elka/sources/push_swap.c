/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:31:20 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/17 18:56:10 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_tab *a)
{
	size_t	i;
	size_t	total_pairs;
	size_t	mistakes;
	float	metric;

	total_pairs = a->size - 1;
	mistakes = 0;
	i = 0;
	while (i < total_pairs)
	{
		if (a->tab[i] > a->tab[i + 1])
			mistakes++;
		i++;
	}
	metric = ((float)mistakes / total_pairs);
	return (metric);
}

void	strategy_selector(size_t strategy, size_t size, t_tab *a, t_tab *b)
{
	float	metric;

	metric = compute_disorder(a);
	if (strategy == 0 || strategy == 4)
	{
		if (metric < 0.2)
			strategy = 1;
		if (metric > 0.2 && metric < 0.5)
			strategy = 2;
		if (metric > 0.5)
			strategy = 3;
	}
	b->tab = malloc(sizeof(int) * size);
	if (!b->tab)
		return ;
	if (strategy == 1)
		simple_sort(a, b);
	else if (strategy == 2)
		medium_sort(a, b, size);
	else if (strategy == 3)
		complex_sort(a, b, size);
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t		strategy;

	strategy = 0;
	if (args[0][0] == '-')
		strategy = ft_strcmp(args[0]);
	if (strategy > 0)
		--size;
	a->size = size;
	b->size = 0;
	set_tab(strategy, a, args, size);
	if (!a->tab)
		return ;
	strategy_selector(strategy, size, a, b);
}
