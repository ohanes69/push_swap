/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:48:46 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/20 19:20:35 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_tab *stack)
{
	stack->sa = 0;
	stack->sb = 0;
	stack->ss = 0;
	stack->pa = 0;
	stack->pb = 0;
	stack->ra = 0;
	stack->rb = 0;
	stack->rr = 0;
	stack->rra = 0;
	stack->rrb = 0;
	stack->rrr = 0;
}

static size_t	nb_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_tab	*a;
	t_tab	*b;
	char	**args;
	size_t	size;

	if (ac < 2)
		return (0);
	a = malloc(sizeof(t_tab));
	b = malloc(sizeof(t_tab));
	init_stack(a);
	args = parsing(ac, av);
	size = nb_args(args);
	push_swap(args, a, b, size);
	free(a);
	free(b);
	return (0);
}
