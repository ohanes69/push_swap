/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 12:02:04 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

size_t	is_flag(char *s)
{
	size_t	flags;

	flags = compare_flag(s);
	return (flags);
}

void	count_flags(char **args, t_tab *stack)
{
	size_t	i;
	size_t	flags;

	i = 0;
	flags = 0;
	while (args[i])
	{
		if (compare_flag(args[i]) == 1)
			stack->simple++;
		if (compare_flag(args[i]) == 2)
			stack->medium++;
		if (compare_flag(args[i]) == 3)
			stack->complex++;
		if (compare_flag(args[i]) == 4)
			stack->adaptive++;
		if (compare_flag(args[i]) == 5)
			stack->bench++;
		i++;
	}
	flags = stack->simple + stack->medium + stack->complex
		+ stack->adaptive + stack->bench;
	if (flags > 2)
		print_error();
}

void	set_table(char **args, t_tab *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (is_flag(args[i]) != 0)
			i++;
		else
		{
			a->tab[j] = is_valid_int(args[i]);
			j++;
			i++;
		}
	}
}

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
	if (is_bench == 5)
		move_use(move, a, metric);
	return ;
}

size_t	move_is_5(t_tab *stack)
{
	if (stack->simple == 1)
		return (1);
	if (stack->medium == 1)
		return (2);
	if (stack->complex == 1)
		return (3);
	if (stack->adaptive == 1)
		return (4);
	return (0);
}

size_t	return_move(t_tab *stack)
{
	if (stack->bench == 1)
		return (5);
	if (stack->simple == 1)
		return (1);
	if (stack->medium == 1)
		return (2);
	if (stack->complex == 1)
		return (3);
	if (stack->adaptive == 1)
		return (4);
	return (0);
}

void	is_same_flags(t_tab	*stack)
{
	if (stack->simple > 1 || stack->medium > 1 || stack->complex > 1
		|| stack->adaptive > 1 || stack->bench > 1)
		print_error();
}

void	set_tab_and_indexing(t_tab *a, char **args, size_t size)
{
	is_same_flags(a);
	set_table(args, a);
	indexing(a, size);
	is_duplicate(a, size);
}

void	if_bench_flag(size_t move, size_t size, t_tab *a, t_tab *b)
{
	float	metric;

	metric = compute_disorder(a);
	if (move == 0 || move == 4)
		move = choose_metric(move, metric);
	choose_sort(move, a, b, size);
	move_use(move, a, metric);
}

void	if_no_bench_flag(size_t move, size_t size, t_tab *a, t_tab *b)
{
	float	metric;

	metric = compute_disorder(a);
	if (move >= 1 && move <= 3)
		choose_sort(move, a, b, size);
	else if (move == 0 || move == 4)
	{
		move = choose_metric(move, metric);
		choose_sort(move, a, b, size);
	}
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	move;
	size_t	is_bench;
	float	metric;

	is_bench = 0;
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
	count_flags(args, a);
	set_tab_and_indexing(a, args, size);
	metric = compute_disorder(a);
	move = return_move(a);
	if (move == 5)
	{
		is_bench = 5;
		move = move_is_5(a);
	}
	if (metric == 0)
	{
		if_nothing_to_sort(metric, is_bench, move, a);
		return ;
	}
	if (is_bench == 5)
		if_bench_flag(move, size, a, b);
	else
		if_no_bench_flag(move, size, a, b);
	free(a->tab);
	free(b->tab);
}
