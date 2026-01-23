/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:02:56 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/23 17:40:49 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_tab *stack)
{
	stack->simple = 0;
	stack->medium = 0;
	stack->complex = 0;
	stack->adaptive = 0;
	stack->bench = 0;
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

size_t	number_of_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

size_t	find_number_of_int(char **args)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		if (is_integer(args[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	t_tab	*a;
	t_tab	*b;
	char	**args;
	size_t	size;

	if (ac <= 2)
		return (0);
	args = NULL;
	a = malloc(sizeof(t_tab));
	b = malloc(sizeof(t_tab));
	if (!a || !b)
	{
		free(a);
		free(b);
		return (1);
	}
	init_stack(a);
	args = parsing(ac, av);
	if (!args)
	{
		free_all(args, a, b);
		return (1);
	}
	size = find_number_of_int(args);
	push_swap(args, a, b, size);
	free_all(args, a, b);
}
