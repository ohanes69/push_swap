/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:07:23 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/25 17:49:36 by samarkar         ###   ########lyon.fr   */
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

static void	operations(t_strategy *strategy)
{
	int	total_ops;

	total_ops = strategy->sa + strategy->sb + strategy->ss
		+ strategy->pa + strategy->pb + strategy->ra + strategy->rb
		+ strategy->rr + strategy->rra + strategy->rrb + strategy->rrr;
	ft_printf("\n[bench] total_ops: ");
	ft_printf("%d", total_ops);
	ft_printf("\n[bench] ");
	ft_printf("sa: %d ", strategy->sa);
	ft_printf("sb: %d ", strategy->sb);
	ft_printf("ss: %d ", strategy->ss);
	ft_printf("pa: %d ", strategy->pa);
	ft_printf("pb: %d ", strategy->pb);
	ft_printf("\n[bench] ");
	ft_printf("ra: %d ", strategy->ra);
	ft_printf("rb: %d ", strategy->rb);
	ft_printf("rr: %d ", strategy->rr);
	ft_printf("rra: %d ", strategy->rra);
	ft_printf("rrb: %d ", strategy->rrb);
	ft_printf("rrr: %d\n", strategy->rrr);
}

void	strategy_use(t_data *data, t_strategy *strategy, float metric)
{
	print_disorder(metric);
	ft_printf("\n[bench] ");
	ft_printf("strategy:");
	if (data->flag1 == 1)
		ft_printf(" Simple / O(n²)");
	else if (data->flag1 == 2)
		ft_printf(" Medium / O(n√n)");
	else if (data->flag1 == 3)
		ft_printf(" Complex / O(n log n)");
	operations(strategy);
}
