/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:58:08 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/22 19:10:38 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

static void	ft_put_in_buffer(char c, t_buffer *buffer)
{
	buffer->str[buffer->len] = c;
	buffer->len++;
}

static void	ft_nbr_in_buffer(int nb, t_buffer *buffer)
{
	if (nb < 0)
	{
		ft_put_in_buffer('-', buffer);
		nb = -nb;
	}
	if (nb >= 10)
		ft_nbr_in_buffer(nb / 10, buffer);
	ft_put_in_buffer(nb % 10 + '0', buffer);
}

static void	check_type(char c, va_list args, t_buffer *buffer)
{
	if (c == 'c')
		ft_put_in_buffer((char)va_arg(args, int), buffer);
	else if (c == '%')
		ft_put_in_buffer('%', buffer);
	else if (c == 'd')
		ft_nbr_in_buffer(va_arg(args, int), buffer);
}

void	ft_printf(const char *s, ...)
{
	va_list		args;
	t_buffer	buffer;
	int			i;

	i = 0;
	buffer.len = 0;
	va_start(args, s);
	if (!s)
		return ;
	while (s[i])
	{
		if (s[i] == '%')
			check_type(s[++i], args, &buffer);
		else
			ft_put_in_buffer(s[i], &buffer);
		i++;
	}
	va_end(args);
	write(2, buffer.str, buffer.len);
	return ;
}
