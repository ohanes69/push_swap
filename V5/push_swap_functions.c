/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:59:21 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/24 17:58:52 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_tab *tab, char c)
{
	int	tmp;

	if (tab->size_a >= 2 && c == 'a')
	{
		tmp = tab->a[0];
		tab->a[0] = tab->a[1];
		tab->a[1] = tmp;
		write (1, "sa\n", 3);
	}
	else if (tab->size_b >= 2 && c == 'b')
	{
		tmp = tab->b[0];
		tab->b[0] = tab->b[1];
		tab->b[1] = tmp;
		write (1, "sb\n", 3);
	}
}

void	push_a(t_tab *tab)
{
	size_t	i;

	if (tab->size_b <= 0)
		return ;
	i = tab->size_a;
	while (i > 0)
	{
		tab->a[i] = tab->a[i - 1];
		--i;
	}
	tab->a[0] = tab->b[0];
	tab->size_a++;
	i = 1;
	while (i < tab->size_b)
	{
		tab->b[i - 1] = tab->b[i];
		++i;
	}
	tab->size_b--;
	write (1, "pa\n", 3);
}

void	push_b(t_tab *tab)
{
	size_t	i;

	if (tab->size_a <= 0)
		return ;
	i = tab->size_b;
	while (i > 0)
	{
		tab->b[i] = tab->b[i - 1];
		--i;
	}
	tab->b[0] = tab->a[0];
	tab->size_b++;
	i = 1;
	while (i < tab->size_a)
	{
		tab->a[i - 1] = tab->a[i];
		++i;
	}
	tab->size_a--;
	write (1, "pb\n", 3);
}
