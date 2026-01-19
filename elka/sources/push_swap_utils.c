/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:59:21 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/16 20:10:07 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_tab *stack, char *str)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->tab[0];
		stack->tab[0] = stack->tab[1];
		stack->tab[1] = tmp;
		if (str)
		{
			write (1, str, 2);
			write (1, "\n", 1);
		}
	}
}

void	swap_ab(t_tab *a, t_tab *b)
{
	swap(a, NULL);
	swap(b, NULL);
	write (1, "ss", 2);
	write (1, "\n", 1);
}

void	push(t_tab *stack1, t_tab *stack2, char *str)
{
	size_t	i;

	if (stack1->size <= 0)
		return ;
	i = stack2->size;
	while (i > 0)
	{
		stack2->tab[i] = stack2->tab[i - 1];
		--i;
	}
	stack2->tab[0] = stack1->tab[0];
	stack2->size++;
	i = 1;
	while (i < stack1->size)
	{
		stack1->tab[i - 1] = stack1->tab[i];
		++i;
	}
	stack1->size--;
	write (1, str, 2);
	write (1, "\n", 1);
}
