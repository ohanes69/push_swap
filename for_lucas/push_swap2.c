/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:09:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/22 14:45:55 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap2.h"
#include <stdio.h>

size_t	check_flags2(char *s)
{
	size_t	flags;

	flags = 0;
	if (ft_strcmp(s) == 1)
		flags++;
	if (ft_strcmp(s) == 2)
		flags++;
	if (ft_strcmp(s) == 3)
		flags++;
	if (ft_strcmp(s) == 4)
		flags++;
	if (ft_strcmp(s) == 5)
		flags++;
	return (flags);
}

size_t	check_flags(char **args, t_tab *stack)
{
	size_t	i;
	size_t	flags;

	i = 0;
	flags = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i]) == 1)
			stack->simple++;
		if (ft_strcmp(args[i]) == 2)
			stack->medium++;
		if (ft_strcmp(args[i]) == 3)
			stack->complex++;
		if (ft_strcmp(args[i]) == 4)
			stack->adaptative++;
		if (ft_strcmp(args[i]) == 5)
			stack->bench++;
		i++;
	}
	flags = stack->simple + stack->medium + stack->complex
	+ stack->adaptative + stack->bench;
	if (flags > 2)
		print_error();
	return (flags);
}

void	set_table(char **args, t_tab *a)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		a->tab[i] = is_valid_int(args[i]);
		i++;
	}
	// indexing(a, size);
	// is_duplicate(a, size);
}

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size)
{
	t_tab	*stack;
	size_t	flags;
	char	**new_stack;

	a = malloc(sizeof(t_tab));
	a->size = size;
	a->tab = malloc(sizeof(int) * size);
	b = malloc(sizeof(t_tab));
	b->size = size;
	b->tab = malloc(sizeof(int) * size);
	stack = malloc(sizeof(t_tab));
	flags = check_flags(args, stack);

	if (flags == 0)
		set_table(args, a);
	else
	{
		new_stack = new_tab(args, size);
		set_table(new_stack, a);
	}

	size_t i = 0;
	while (i < size)
	{
		printf("%d\n", a->tab[i]);
		i++;
	}

	// new_stack = new_tab(args, size);
}
