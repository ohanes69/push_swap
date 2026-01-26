/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:18:55 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/23 18:31:15 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include <stdio.h>

int	is_integer(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		if (!s[i])
			return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_int(const char *s)
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

void	is_duplicate(t_tab *a, size_t size)
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

int	find_index(int nb, size_t size, int *buffer)
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

void	indexing(t_tab *a, size_t size)
{
	size_t	i;
	int		*buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
	{
		free(buffer);
		return ;
	}
	buffer = ft_memcpy(buffer, a->tab, size * sizeof(int));
	i = 0;
	while (i < size)
	{
		a->tab[i] = find_index(a->tab[i], size, buffer);
		++i;
	}
	free(buffer);
}
