/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:55:26 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/24 14:51:07 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_tab *tab)
{
	size_t	i;
	size_t 	j;
	size_t	total_pairs;
	size_t	mistakes;
	float	metric;

	total_pairs = 0;
	mistakes = 0;
	i = 0;
	if (tab->size_a == 1)
		return (0);
	while (i < tab->size_a - 1)
	{
		j = i + 1;
		while (j < tab->size_a)
		{
			++total_pairs;
			if (tab->a[i] > tab->a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	metric = ((float)mistakes / total_pairs);
	return (metric);
}
