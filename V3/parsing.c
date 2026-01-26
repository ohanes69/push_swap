/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:32:02 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 08:56:02 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, len_s1);
	ft_memcpy(join + len_s1, s2, len_s2);
	join[len_s1 + len_s2] = '\0';
	return (join);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	dup[len] = '\0';
	return (dup);
}

bool	is_duplicate(t_tab *tab, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (tab->a[i] == value)
			return (false);
		i++;
	}
	return (true);
}

static int	is_valid_int(const char *s, t_data *data)
{
	size_t	i;
	size_t	digits;
	long	value;

	i = 0;
	digits = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		digits++;
		i++;
	}
	if (digits > 10)
		return (0);
	value = ft_atoi_long(s);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	data->value = (int)value;
	return (1);
}

static bool	is_flag(char *s, t_data *data)
{
	size_t	flags;

	if (!s[0] || !s[1] || s[0] != '-' || s[1] != '-')
    	return (false);
	flags = ft_strcmp(s);
	if (flags == 0)
		return (false);
	if (flags == data->flag1 || flags == data->flag2)
		return (false);
	if (flags >= 1 && flags <= 4)
	{
		if (data->flag1 != 0)
			return (false);
		else
			data->flag1 = flags;
	}
	if (flags == 5)
	{
		if (data->flag2 != 0)
			return (false);
		else
			data->flag2 = flags;	
	}
	return (true);
}

static int	count_flag(t_data *data, char **args)
{
	size_t	i;

	data->nb_flag = 0;
	i = 0;
	while (i < data->size)
	{
		if (is_flag(args[i], data) != 0)
			data->nb_flag++;
		i++;
	}
	return (data->nb_flag);
}

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
			if(!is_valid_int(args[i], data) || !is_duplicate(tab, data->value, j))
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

static char	*join_args(int argc, char **argv)
{
	char	*args;
	char	*tmp;
	size_t	i;

	args = ft_strdup(argv[1]);
	i = 2;
	if (!args)
		return (NULL);
	while (i < argc)
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
	count_flag(data, args);
	data->flag1 = 0;
	data->flag2 = 0;
	if (!init_tab(args, data, tab))
	{	
		ft_free_tab(args);
		return (false);
	}
	ft_free_tab(args);
	data->size -= data->nb_flag;
	indexing(tab, data);
	free(tab->a);
	return (true);
}
