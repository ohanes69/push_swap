/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:02:56 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 11:46:16 by lucpelle         ###   ########.fr       */
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
	data->move = 0;
	data->bench = 0;
	data->flag1 = 0;
	data->flag2 = 0;
	data->nb_flag = 0;
	data->value = 0;
}

int	main(int ac, char **av)
{
	t_move 	move;
	t_data 		data;
	t_tab		tab;

	if (ac <= 2)
		return (0);
	init_stack(&move);
	init_data(&data);
	if (!parsing(ac, av, &data, &tab))
	{
		write (2, "Error\n", 6);
		return (1);	
	}
	// push_swap(&tab, &data, &move);
}
