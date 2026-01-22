/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:48:46 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/21 19:15:18 by samarkar         ###   ########lyon.fr   */
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

static void	free_all(char **args, t_tab *a, t_tab *b)
{
	ft_free_tab(args);
	free(a);
	free(b);
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
	if (!a)
	{
		free(a);
		return (1);
	}
	b = malloc(sizeof(t_tab));
	if (!b)
	{
		free(a);
		free(b);
		return (1);
	}
	args = NULL;
	init_stack(a);
	args = parsing(ac, av);
	if (!args)
	{
		free_all(args, a, b);
		return (1);
	}
	size = nb_args(args);
	push_swap(args, a, b, size);
	free(a->tab);
	free(b->tab);
	free_all(args, a, b);
}
