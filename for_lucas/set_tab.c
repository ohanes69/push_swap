/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:41:14 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 12:02:04 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	set_tab_below_5(size_t move, t_tab *a, char **args, size_t size)
{
	size_t	i;

	if (move > 0)
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
	return (move);
}

size_t	bench_move(size_t move, t_tab *a, char **args, size_t size)
{
	size_t	i;

	i = 1;
	move = compare_flag(args[i]);
	if (move >= 1 && move <= 4)
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
	return (move);
}

size_t	set_tab(size_t move, t_tab *a, char **args, size_t size)
{
	if (move == 5)
	{
		move = bench_move(move, a, args, size);
		indexing(a, size);
		is_duplicate(a, size);
		return (move);
	}
	else
	{
		move = set_tab_below_5(move, a, args, size);
		indexing(a, size);
		is_duplicate(a, size);
	}
	return (move);
}
