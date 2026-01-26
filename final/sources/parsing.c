/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:32:02 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 23:21:43 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>

bool	init_tab(char **args, t_data *data, t_tab *tab)
{
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	tab->a = malloc(sizeof(int) * (data->size - data->nb_flag));
	if (!tab->a)
		return (false);
	while (i < data->size)
	{
		if (!is_flag(args[i], data))
		{
			if (!is_valid_int(args[i], data)
				|| !is_duplicate(tab, data->value, j))
			{
				free(tab->a);
				return (false);
			}
			tab->a[j++] = data->value;
		}
		++i;
	}
	if (data->nb_flag > 2)
		return (false);
	return (true);
}

static int	only_spaces_or_flags(char **args)
{
	if (args[0] == NULL)
		return (0);
	if (compare_flag(args[0]) > 0 && args[1] == NULL)
		return (0);
	if (compare_flag(args[0]) > 0 && compare_flag(args[1]) > 0
		&& args[2] == NULL)
		return (0);
	return (1);
}

static char	*join_args(int argc, char **argv)
{
	char	*args;
	char	*tmp;
	size_t	i;

	args = ft_strdup(argv[1]);
	i = 2;
	if (!args)
		return (NULL);
	while (i < (size_t)argc)
	{
		tmp = ft_strjoin(args, " ");
		free(args);
		if (!tmp)
			return (NULL);
		args = tmp;
		tmp = ft_strjoin(args, argv[i]);
		free(args);
		if (!tmp)
			return (NULL);
		args = tmp;
		++i;
	}
	return (args);
}

bool	parsing(int argc, char **argv, t_data *data, t_tab *tab)
{
	char	**args;
	char	*args_join;

	args_join = join_args(argc, argv);
	if (!args_join)
		return (false);
	args = ft_split(args_join, ' ', data);
	free(args_join);
	if (!args)
		return (false);
	if (only_spaces_or_flags(args) == 0)
		return (false);
	count_flag(data, args);
	data->flag_strategy = NONE;
	data->flag_bench = NONE;
	if (!init_tab(args, data, tab))
	{
		ft_free_tab(args);
		return (false);
	}
	ft_free_tab(args);
	data->size -= data->nb_flag;
	if (!indexing(tab, data))
		return (false);
	return (true);
}
