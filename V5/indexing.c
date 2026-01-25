/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:18:55 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/25 18:11:17 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include <stdio.h>

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

void	indexing(t_tab *tab)
{
	size_t	i;
	int		*buffer;

	buffer = malloc(sizeof(int) * tab->size_a);
	if (!buffer)
	{
		free(buffer);
		return ;
	}
	buffer = ft_memcpy(buffer, tab->a, tab->size_a * sizeof(int));
	i = 0;
	while (i < tab->size_a)
	{
		tab->a[i] = find_index(tab->a[i], tab->size_a, buffer);
		++i;
	}
	free(buffer);
}
