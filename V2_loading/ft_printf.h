/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:51:21 by lucpelle          #+#    #+#             */
/*   Updated: 2025/12/15 12:12:18 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# ifndef BUF_SIZE
#  define BUF_SIZE 1024
# endif

typedef struct s_buffer
{
	char	str[BUF_SIZE];
	int		len;
	int		total_written;	
}	t_buffer;

int			ft_printf(const char *s, ...);
void		ft_put_in_buffer(char c, t_buffer *buffer);
void		ft_unsigned_in_buffer(unsigned int nb, t_buffer *buffer);
void		ft_str_in_buffer(char *s, t_buffer *buffer);
void		ft_nbr_in_buffer(int nb, t_buffer *buffer);
void		ft_print_ptr(unsigned long nb, t_buffer *buffer);
void		ft_hexa(unsigned int nb, t_buffer *buffer, char c);

#endif
