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

size_t	choose_metric(size_t move, float metric)
{
	if (metric < 0.2)
		move = 1;
	if (metric >= 0.2 && metric < 0.5)
		move = 2;
	if (metric >= 0.5)
		move = 3;
	return (move);
}

void	choose_sort(size_t move, t_tab *a, t_tab *b, size_t size)
{
	if (move == 1)
		simple_sort(a, b);
	else if (move == 2)
		medium_sort(a, b, size);
	else if (move == 3)
		complex_sort(a, b, size);
}

void	if_nothing_to_sort(float metric, size_t is_bench, size_t move, t_tab *a)
{
	if (metric == 0.000000 && is_bench != 5)
		return ;
	else if (metric == 0.000000 && is_bench == 5)
	{
		move_use(move, a, metric);
		return ;
	}
}

size_t	find_size(char **args, size_t move, size_t size)
{
	if (move > 0 && args[1][0] == '-' && args[1][1] == '-')
		--size;
	if (move > 0)
		--size;
	return (size);
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	move;
	size_t	is_bench;
	float	metric;

	move = 0;
	if (args[0][0] == '-' && args[0][1] == '-')
		move = compare_flag(args[0]);
	is_bench = move;
	size = find_size(args, move, size);
	__builtin_printf("%zu", size);
	// a->size = size;
	// a->tab = malloc(sizeof(int) * size);
	// if (!a->tab)
	// {
	// 	free(a->tab);
	// 	return ;
	// }
	// b->size = 0;
	// move = set_tab(move, a, args, size);
	// metric = compute_disorder(a);
	// if (metric == 0.000000)
	// {
	// 	if_nothing_to_sort(metric, is_bench, move, a);
	// 	return ;
	// }
	// if (move == 0 || move == 4)
	// 	move = choose_metric(move, metric);
	// b->tab = malloc(sizeof(int) * size);
	// if (!b->tab)
	// {
	// 	free(b->tab);
	// 	return ;
	// }
	// choose_sort(move, a, b, size);
	// if (is_bench == 5)
	// 	move_use(move, a, metric);
}
