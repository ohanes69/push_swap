/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:36:10 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 14:27:55 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

static size_t	compare_flag(char *s1)
{
	size_t	i;
	size_t	j;
	char	*comp[5];

	comp[0] = "--simple";
	comp[1] = "--medium";
	comp[2] = "--complex";
	comp[3] = "--adaptive";
	comp[4] = "--bench";
	j = 0;
	while (j < 5)
	{
		i = 0;
		while ((s1[i] && comp[j][i]) && s1[i] == comp[j][i])
			i++;
		if (s1[i] == '\0' && comp[j][i] == '\0')
			return (j + 1);
		++j;
	}
	return (0);
}

int	count_flag(t_data *data, char **args)
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

int	is_valid_int(const char *s, t_data *data)
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

bool	is_flag(char *s, t_data *data)
{
	size_t	flags;

	if (!s[0] || !s[1] || s[0] != '-' || s[1] != '-')
		return (false);
	flags = compare_flag(s);
	if (flags == NONE)
		return (false);
	if (flags == data->flag1 || flags == data->flag2)
		return (false);
	if (flags >= SIMPLE && flags <= ADAPTIVE)
	{
		if (data->flag1 != NONE)
			return (false);
		else
			data->flag1 = flags;
	}
	if (flags == BENCH)
	{
		if (data->flag2 != NONE)
			return (false);
		else
			data->flag2 = flags;
	}
	return (true);
}
