/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/23 20:27:12 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

size_t	is_flag(char *s)
{
	size_t	flags;

	flags = 0;
	if (ft_strcmp(s) == 1)
		flags++;
	if (ft_strcmp(s) == 2)
		flags++;
	if (ft_strcmp(s) == 3)
		flags++;
	if (ft_strcmp(s) == 4)
		flags++;
	if (ft_strcmp(s) == 5)
		flags++;
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
		if (ft_strcmp(args[i]) == 1)
			stack->simple++;
		if (ft_strcmp(args[i]) == 2)
			stack->medium++;
		if (ft_strcmp(args[i]) == 3)
			stack->complex++;
		if (ft_strcmp(args[i]) == 4)
			stack->adaptive++;
		if (ft_strcmp(args[i]) == 5)
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
	if (is_bench == 5)
		strategy_use(strategy, a, metric);
	return ;
}

size_t	strategy_is_5(t_tab *stack)
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

size_t	return_strategy(t_tab *stack)
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

void	if_bench_flag(size_t strategy, size_t size, t_tab *a, t_tab *b)
{
	float	metric;

	metric = compute_disorder(a);
	if (strategy == 0 || strategy == 4)
		strategy = choose_metric(strategy, metric);
	choose_sort(strategy, a, b, size);
	strategy_use(strategy, a, metric);
}

void	if_no_bench_flag(size_t strategy, size_t size, t_tab *a, t_tab *b)
{
	float	metric;

	metric = compute_disorder(a);
	if (strategy >= 1 && strategy <= 3)
		choose_sort(strategy, a, b, size);
	else if (strategy == 0 || strategy == 4)
	{
		strategy = choose_metric(strategy, metric);
		choose_sort(strategy, a, b, size);
	}
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	strategy;
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
	strategy = return_strategy(a);
	if (strategy == 5)
	{
		is_bench = 5;
		strategy = strategy_is_5(a);
	}
	if (metric == 0)
	{
		if_nothing_to_sort(metric, is_bench, strategy, a);
		return ;
	}
	if (is_bench == 5)
		if_bench_flag(strategy, size, a, b);
	else
		if_no_bench_flag(strategy, size, a, b);
	free(a->tab);
	free(b->tab);
}
