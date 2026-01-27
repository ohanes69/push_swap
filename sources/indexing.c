/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:18:55 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 13:23:51 by lucpelle         ###   ########.fr       */
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

bool	indexing(t_tab *tab, t_data *data)
{
	size_t	i;
	int		*buffer;

	buffer = malloc(sizeof(int) * data->size);
	if (!buffer)
	{
		free(tab->a);
		return (false);
	}
	buffer = ft_memcpy(buffer, tab->a, data->size * sizeof(int));
	i = 0;
	while (i < data->size)
	{
		tab->a[i] = find_index(tab->a[i], data->size, buffer);
		++i;
	}
	free(buffer);
	return (true);
}
