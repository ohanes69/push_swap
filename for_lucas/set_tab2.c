/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:13 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/22 11:11:30 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap2.h"

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

	i = 0;
	strategy = ft_strcmp(args[i]);
	if (strategy == 5)
		strategy = ft_strcmp(args[i + 1]);
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

void	set_tab(t_tab *a, char **args, size_t size)
{
	
}
