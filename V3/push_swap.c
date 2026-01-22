/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/22 21:26:50 by samarkar         ###   ########lyon.fr   */
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

size_t	count_flags(char **args, t_tab *stack)
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
			stack->adaptative++;
		if (ft_strcmp(args[i]) == 5)
			stack->bench++;
		i++;
	}
	flags = stack->simple + stack->medium + stack->complex
		+ stack->adaptative + stack->bench;
	if (flags > 2)
		print_error();
	return (flags);
}

void	set_table(char **args, t_tab *a)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		a->tab[i] = is_valid_int(args[i]);
		i++;
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
	if (metric == 0 && is_bench != 5)
		return ;
	else if (metric == 0 && is_bench == 5)
	{
		strategy_use(strategy, a, metric);
		return ;
	}
}

size_t	strategy_is_5(t_tab *stack)
{
	if (stack->simple == 1)
		return (1);
	if (stack->medium == 1)
		return (2);
	if (stack->complex == 1)
		return (3);
	if (stack->adaptative == 1)
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
	if (stack->adaptative == 1)
		return (4);
	return (0);
}

void	is_same_flags(t_tab	*stack)
{
	if (stack->simple > 1 || stack->medium > 1 || stack->complex > 1
		|| stack->adaptative > 1 || stack->bench > 1)
		print_error();
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	size_t	flags;
	char	**new_stack;
	size_t	strategy;
	size_t	is_bench;
	float 	metric;

	is_bench = 0;
	a = malloc(sizeof(t_tab));
	a->size = size;
	a->tab = malloc(sizeof(int) * size);
	b = malloc(sizeof(t_tab));
	b->size = 0;
	b->tab = malloc(sizeof(int) * size);
	flags = count_flags(args, a);

	is_same_flags(a);

	if (flags == 0)
		set_table(args, a);
	else
	{
		new_stack = new_tab(args, size);
		set_table(new_stack, a);
	}
	indexing(a, size);
	is_duplicate(a, size);

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
	{
		if (strategy == 0 || strategy == 4)
			strategy = choose_metric(strategy, metric);
		choose_sort(strategy, a, b, size);
		strategy_use(strategy, a, metric);
	}
	else if (strategy >= 1 && strategy <= 3)
		choose_sort(strategy, a, b, size);
	else if (strategy == 0 || strategy == 4)
	{
		strategy = choose_metric(strategy, metric);
		choose_sort(strategy, a, b, size);
	}
}
