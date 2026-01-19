/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:58:08 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/19 18:34:02 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_put_in_buffer(char c, t_buffer *buffer)
{
	if ((buffer->len) >= BUF_SIZE)
	{
		write (2, buffer->str, buffer->len);
		buffer->len = 0;
		buffer->total_written += BUF_SIZE;
	}
	buffer->str[buffer->len] = c;
	buffer->len++;
}

static void	check_type(char c, va_list args, t_buffer *buffer)
{
	unsigned long	ptr;

	if (c == 'c')
		ft_put_in_buffer((char)va_arg(args, int), buffer);
	else if (c == '%')
		ft_put_in_buffer('%', buffer);
	else if (c == 's')
		ft_str_in_buffer(va_arg(args, char *), buffer);
	else if (c == 'd' || c == 'i')
		ft_nbr_in_buffer(va_arg(args, int), buffer);
	else if (c == 'u')
		ft_unsigned_in_buffer(va_arg(args, unsigned int), buffer);
	else if (c == 'X' || c == 'x')
		ft_hexa(va_arg(args, unsigned int), buffer, c);
	else if (c == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (ptr == 0)
			ft_str_in_buffer("(nil)", buffer);
		else
		{
			ft_str_in_buffer("0x", buffer);
			ft_print_ptr(ptr, buffer);
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_buffer	buffer;
	int			i;

	i = 0;
	buffer.len = 0;
	buffer.total_written = 0;
	va_start(args, s);
	if (!s)
		return (-1);
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
	return (buffer.len + buffer.total_written);
}
