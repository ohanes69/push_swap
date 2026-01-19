/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:22:22 by lucpelle          #+#    #+#             */
/*   Updated: 2025/12/12 12:39:41 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	ft_hexa(unsigned int nb, t_buffer *buffer, char c)
{
	if (c == 'X')
	{
		if (nb >= 16)
			ft_hexa((nb / 16), buffer, c);
		ft_put_in_buffer((HEX_UP[nb % 16]), buffer);
	}
	if (c == 'x')
	{
		if (nb >= 16)
			ft_hexa((nb / 16), buffer, c);
		ft_put_in_buffer((HEX_LOW[nb % 16]), buffer);
	}
}

void	ft_print_ptr(unsigned long nb, t_buffer *buffer)
{
	if (nb >= 16)
		ft_print_ptr((nb / 16), buffer);
	ft_put_in_buffer((HEX_LOW[nb % 16]), buffer);
}

void	ft_nbr_in_buffer(int nb, t_buffer *buffer)
{
	if (nb == INT_MIN)
	{
		ft_str_in_buffer("-2147483648", buffer);
		return ;
	}
	if (nb < 0)
	{
		ft_put_in_buffer('-', buffer);
		nb = -nb;
	}
	if (nb >= 10)
		ft_nbr_in_buffer(nb / 10, buffer);
	ft_put_in_buffer(nb % 10 + '0', buffer);
}

void	ft_str_in_buffer(char *s, t_buffer *buffer)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		ft_put_in_buffer(s[i++], buffer);
}

void	ft_unsigned_in_buffer(unsigned int nb, t_buffer *buffer)
{
	if (nb >= 10)
		ft_unsigned_in_buffer(nb / 10, buffer);
	ft_put_in_buffer(nb % 10 + '0', buffer);
}
