/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:41:14 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/21 18:57:00 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_tab(size_t is_bench, size_t strategy, t_tab *a, char **args, size_t size)
{
	size_t i;
	size_t j;
	
	i = 0;
	j = 0;
	if (is_bench > 0)
		i++;
	if (strategy > 0)
		i++;
	while (size > 0)
	{
		a->tab[j] = is_valid_int(args[i]);
		++i;
		++j;
		--size;
	}
}
