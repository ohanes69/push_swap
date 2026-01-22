/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:56:21 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/16 20:05:14 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_tab *stack, char *str)
{
	size_t	i;
	int		temp;

	if (stack->size >= 2)
	{
		i = 0;
		temp = stack->tab[0];
		while (i < stack->size - 1)
		{
			stack->tab[i] = stack->tab[i + 1];
			++i;
		}
		stack->tab[stack->size - 1] = temp;
		if (str)
		{
			write (1, str, 2);
			write (1, "\n", 1);
		}
	}
}

void	rotate_ab(t_tab *a, t_tab *b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write (1, "rr", 2);
	write (1, "\n", 1);
}

void	reverse_rotate(t_tab *stack, char *str)
{
	size_t	i;
	int		temp;

	if (stack->size >= 2)
	{
		i = stack->size - 1;
		temp = stack->tab[i];
		while (i > 0)
		{
			stack->tab[i] = stack->tab[i - 1];
			--i;
		}
		stack->tab[0] = temp;
		if (str)
		{
			write (1, str, 3);
			write (1, "\n", 1);
		}
	}
}

void	reverse_rotate_ab(t_tab *a, t_tab *b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	write (1, "rrr", 3);
	write (1, "\n", 1);
}
