/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:31:20 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/26 12:02:04 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


static void	move_selector(float metric, size_t move, t_tab *a, t_tab *b, size_t size)
{
	if (move == 0 || move == 4)
	{
		if (metric < 0.2)
			simple_sort(a, b);
		if (metric >= 0.2 && metric < 0.5)
			medium_sort(a, b, size);
		if (metric >= 0.5)
			complex_sort(a, b, size);
	}
	else if (move == 1)
		simple_sort(a, b);
	else if (move == 2)
		medium_sort(a, b, size);
	else if (move == 3)
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

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	move;
	size_t	is_bench;
	size_t	i;
	float	metric;

	move = 0;
	is_bench = 0;
	i = 0;
	
	if (args[0][0] == '-' && args[0][1] == '-')
	{
		move = compare_flag(args[0]);
		if (move == 0)
			return ;
		size--;
		i++;
	}
	if (args[1][0] == '-' && args[1][1] == '-')
	{
		is_bench = compare_flag(args[1]);
		if (move == 0)
			return ;
		size--;
		i++;
	}
	if (move == is_bench && move != 0)
		return ;
	if (move == 5)
	{
		int	tmp;
		tmp = move;
		move = is_bench;
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
	i = 0;
	if (metric == 0.000000 && is_bench == 5)
	{
		move_use(move, a, metric);
		free(a->tab);
		free(b->tab);
		return ;
	}
	move_selector(metric, move, a, b, size);
	if (is_bench == 5)
		move_use(move, a, metric);
	free(a->tab);
	free(b->tab);
}
