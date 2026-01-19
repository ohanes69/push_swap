/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:32:02 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/15 18:01:24 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

size_t	count_args(int argc, char **argv)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	count;

	i = 1;
	count = 0;
	while (i < (size_t)argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		if (!split)
			print_error();
		while (split[j])
		{
			count++;
			j++;
		}
		ft_free_tab(split);
		i++;
	}
	if (count == 0)
		print_error();
	return (count);
}

void	fill_args(char **args, char **split, size_t *k)
{
	size_t	j;

	j = 0;
	while (split[j])
	{
		args[*k] = ft_strdup(split[j], '\n');
		if (!args[*k])
		{
			ft_free_tab(split);
			ft_free_tab(args);
			print_error();
		}
		j++;
		(*k)++;
	}
}

char	**parsing(int argc, char **argv)
{
	char	**args;
	char	**split;
	size_t	total;
	size_t	i;
	size_t	k;

	total = count_args(argc, argv);
	args = ft_calloc(total + 1, sizeof(char *));
	if (!args)
		print_error();
	i = 1;
	k = 0;
	while (i < (size_t)argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			print_error();
		fill_args(args, split, &k);
		ft_free_tab(split);
		i++;
	}
	return (args);
}
