/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:07:23 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 11:46:16 by lucpelle         ###   ########.fr       */
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

static void	operations(t_tab *a)
{
	int	total_ops;

	total_ops = a->sa + a->sb + a->ss + a->pa + a->pb
		+ a->ra + a->rb + a->rr + a->rra + a->rrb + a->rrr;
	ft_printf("\n[bench] total_ops: ");
	ft_printf("%d", total_ops);
	ft_printf("\n[bench] ");
	ft_printf("sa: %d ", a->sa);
	ft_printf("sb: %d ", a->sb);
	ft_printf("ss: %d ", a->ss);
	ft_printf("pa: %d ", a->pa);
	ft_printf("pb: %d ", a->pb);
	ft_printf("\n[bench] ");
	ft_printf("ra: %d ", a->ra);
	ft_printf("rb: %d ", a->rb);
	ft_printf("rr: %d ", a->rr);
	ft_printf("rra: %d ", a->rra);
	ft_printf("rrb: %d ", a->rrb);
	ft_printf("rrr: %d\n", a->rrr);
}

void	move_use(size_t move, t_tab *a, float metric)
{
	print_disorder(metric);
	ft_printf("\n[bench] ");
	ft_printf("move:");
	if (move == 1)
		ft_printf(" Simple / O(n²)");
	else if (move == 2)
		ft_printf(" Medium / O(n√n)");
	else if (move == 3)
		ft_printf(" Complex / O(n log n)");
	operations(a);
}
