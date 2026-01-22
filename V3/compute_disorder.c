/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:55:26 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/22 10:07:09 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

float	compute_disorder(t_tab *a)
{
	size_t	i;
	size_t	total_pairs;
	size_t	mistakes;
	float	metric;

	total_pairs = a->size - 1;
	mistakes = 0;
	i = 0;
	while (i < total_pairs)
	{
		if (a->tab[i] > a->tab[i + 1])
			mistakes++;
		i++;
	}
	metric = ((float)mistakes / total_pairs);
	return (metric);
}

// float	compute_disorder(t_tab *a)
// {
// 	size_t	i;
// 	size_t 	j;
// 	size_t	total_pairs;
// 	size_t	mistakes;
// 	float	metric;

// 	total_pairs = 0;
// 	mistakes = 0;
// 	i = 0;
// 	while (i < a->size - 1)
// 	{
// 		j = i + 1;
// 		while (j < a->size - 1)
// 		{
// 			total_pairs += 1;
// 			if (a->tab[i] > a->tab[j])
// 				mistakes++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	metric = ((float)mistakes / total_pairs);
// 	return (metric);
// }
