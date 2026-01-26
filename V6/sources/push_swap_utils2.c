/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:56:21 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/24 19:46:11 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_tab *tab)
{
	size_t	i;
	int		temp;

	if (tab->size_a >= 2)
	{
		i = 0;
		temp = tab->a[0];
		while (i < tab->size_a - 1)
		{
			tab->a[i] = tab->a[i + 1];
			++i;
		}
		tab->a[tab->size_a - 1] = temp;
		write (1, "ra\n", 3);
	}
}

void	rotate_b(t_tab *tab)
{
	size_t	i;
	int		temp;

	if (tab->size_b >= 2)
	{
		i = 0;
		temp = tab->b[0];
		while (i < tab->size_b - 1)
		{
			tab->b[i] = tab->b[i + 1];
			++i;
		}
		tab->b[tab->size_b - 1] = temp;
		write (1, "rb\n", 3);
	}
}

void	reverse_rotate_a(t_tab *tab)
{
	size_t	i;
	int		temp;

	if (tab->size_a >= 2)
	{
		i = tab->size_a - 1;
		temp = tab->a[i];
		while (i > 0)
		{
			tab->a[i] = tab->a[i - 1];
			--i;
		}
		tab->a[0] = temp;
		write (1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_tab *tab)
{
	size_t	i;
	int		temp;

	if (tab->size_b >= 2)
	{
		i = tab->size_b - 1;
		temp = tab->b[i];
		while (i > 0)
		{
			tab->b[i] = tab->b[i - 1];
			--i;
		}
		tab->b[0] = temp;
		write (1, "rrb\n", 4);
	}
}
