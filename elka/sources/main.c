/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:48:46 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/17 19:15:14 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_all(char **args, t_tab *a, t_tab *b)
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
	char	**args = NULL;
	size_t	size;

	if (ac < 2)
		return (0);
	a = malloc(sizeof(t_tab));
	b = malloc(sizeof(t_tab));
	if (!a || !b)
	{
		free_all(args, a, b);
		return (0);
	}
	args = parsing(ac, av);
	if (!args)
	{
		free_all(args, a, b);
		return (0);
	}
	size = nb_args(args);
	push_swap(args, a, b, size);
	free(a->tab);
	free(b->tab);
	free_all(args, a, b);
}
