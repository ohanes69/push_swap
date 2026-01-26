/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:07:23 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 14:26:13 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_disorder(float disorder)
{
	int	temp;

	ft_printf("[bench] ");
	ft_printf("disorder: ");
	temp = disorder * 100;
	ft_printf("%d", temp);
	ft_printf(".");
	temp = disorder * 1000;
	temp = temp % 100;
	ft_printf("%d", temp);
	ft_printf("%%");
}

static void	count_ops(t_move *move)
{
	int	total_ops;

	total_ops = move->sa + move->sb + move->ss
		+ move->pa + move->pb + move->ra + move->rb
		+ move->rr + move->rra + move->rrb + move->rrr;
	ft_printf("\n[bench] total_ops: ");
	ft_printf("%d", total_ops);
	ft_printf("\n[bench] ");
	ft_printf("sa: %d ", move->sa);
	ft_printf("sb: %d ", move->sb);
	ft_printf("ss: %d ", move->ss);
	ft_printf("pa: %d ", move->pa);
	ft_printf("pb: %d ", move->pb);
	ft_printf("\n[bench] ");
	ft_printf("ra: %d ", move->ra);
	ft_printf("rb: %d ", move->rb);
	ft_printf("rr: %d ", move->rr);
	ft_printf("rra: %d ", move->rra);
	ft_printf("rrb: %d ", move->rrb);
	ft_printf("rrr: %d\n", move->rrr);
}

void	bench(t_data *data, t_move *move, float metric)
{
	print_disorder(metric);
	ft_printf("\n[bench] ");
	ft_printf("strategy:");
	if (metric > 0)
	{
		if (data->flag1 == NONE || data->flag1 == ADAPTIVE)
		{
			if (metric < 0.2)
				ft_printf(" Simple / O(n²)");
			if (metric >= 0.2 && metric < 0.5)
				ft_printf(" Medium / O(n√n)");
			if (metric >= 0.5)
				ft_printf(" Complex / O(n log n)");
		}
		if (data->flag1 == SIMPLE)
			ft_printf(" Simple / O(n²)");
		else if (data->flag1 == MEDIUM)
			ft_printf(" Medium / O(n√n)");
		else if (data->flag1 == COMPLEX)
			ft_printf(" Complex / O(n log n)");
	}
	count_ops(move);
}
