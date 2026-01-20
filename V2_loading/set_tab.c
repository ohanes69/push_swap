/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:41:14 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/20 18:41:44 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	set_tab_below_5(size_t strategy, t_tab *a, char **args, size_t size)
{
	size_t	i;

	if (strategy > 0)
	{
		i = 1;
		while (i - 1 < size)
		{
			a->tab[i - 1] = is_valid_int(args[i]);
			++i;
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			a->tab[i] = is_valid_int(args[i]);
			++i;
		}
	}
	return (strategy);
}

size_t	bench_strategy(size_t strategy, t_tab *a, char **args, size_t size)
{
	size_t	i;

	a->tab = malloc(sizeof(int) * size);
	i = 1;
	strategy = ft_strcmp(args[i]);
	if (strategy >= 1 && strategy <= 4)
	{
		i = 2;
		while (i - 2 < size)
		{
			a->tab[i - 2] = is_valid_int(args[i]);
			++i;
		}
	}
	else
	{
		i = 1;
		while (i - 1 < size)
		{
			a->tab[i - 1] = is_valid_int(args[i]);
			++i;
		}
	}
	return (strategy);
}

size_t	set_tab(size_t strategy, t_tab *a, char **args, size_t size)
{
	a->tab = malloc(sizeof(int) * size);
	if (strategy == 5)
	{
		strategy = bench_strategy(strategy, a, args, size);
		indexing(a, size);
		is_duplicate(a, size);
		return (strategy);
	}
	else
	{
		strategy = set_tab_below_5(strategy, a, args, size);
		indexing(a, size);
		is_duplicate(a, size);
	}
	return (strategy);
}
