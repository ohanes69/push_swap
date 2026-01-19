/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:46:08 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/17 18:57:00 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

static int	is_valid_int(const char *s)
{
	size_t	i;
	size_t	digits;
	long	value;

	i = 0;
	digits = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		if (!s[i])
			print_error();
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			print_error();
		digits++;
		i++;
	}
	if (digits > 10)
		print_error();
	value = ft_atoi_long(s);
	if (value < INT_MIN || value > INT_MAX)
		print_error();
	return ((int)value);
}

static void	is_duplicate(t_tab *a, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a->tab[i] == a->tab[j])
				print_error();
			j++;
		}
		i++;
	}
}

static int	find_index(int nb, size_t size, int *buffer)
{
	size_t	i;
	int		pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		if (buffer[i] < nb)
			++pos;
		++i;
	}
	return (pos);
}

static void	indexing(t_tab *a, size_t size)
{
	size_t	i;
	int		*buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return ;
	buffer = ft_memcpy(buffer, a->tab, size * sizeof(int));
	i = 0;
	while (i < size)
	{
		a->tab[i] = find_index(a->tab[i], size, buffer);
		++i;
	}
	free(buffer);
}

void	set_tab(size_t strategy, t_tab *a, char **args, size_t size)
{
	size_t	i;

	a->tab = malloc(sizeof(int) * size);
	if (!a->tab)
		return ;
	if (strategy > 0)
	{
		i = 1;
		while (i - 1 < size)
		{
			a->tab[i - 1] = is_valid_int(args[i]);
			++i;
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			a->tab[i] = is_valid_int(args[i]);
			++i;
		}
	}
	indexing(a, size);
	is_duplicate(a, size);
}
