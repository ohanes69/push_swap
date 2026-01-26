/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:02:56 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 17:19:35 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_move *stack)
{
	stack->sa = 0;
	stack->sb = 0;
	stack->ss = 0;
	stack->pa = 0;
	stack->pb = 0;
	stack->ra = 0;
	stack->rb = 0;
	stack->rr = 0;
	stack->rra = 0;
	stack->rrb = 0;
	stack->rrr = 0;
}

void	init_data(t_data *data)
{
	data->size = 0;
	data->flag_strategy = 0;
	data->flag_bench = 0;
	data->nb_flag = 0;
	data->value = 0;
}

int	main(int ac, char **av)
{
	t_move		move;
	t_data		data;
	t_tab		tab;

	init_stack(&move);
	init_data(&data);
	if (ac <= 2)
	{
		if (ac == 2)
		{
			if (is_valid_int(av[1], &data))
				return (1);
			else
				write (2, "Error\n", 6);
		}
		return (1);
	}
	if (!parsing(ac, av, &data, &tab))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	push_swap(&tab, &move, &data);
	return (0);
}
