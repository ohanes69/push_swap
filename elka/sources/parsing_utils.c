/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:53:58 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/17 19:22:01 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strcmp(char *s1)
{
	size_t	i;
	size_t	j;
	char	*comp[5];

	comp[0] = "--simple";
	comp[1] = "--medium";
	comp[2] = "--complex";
	comp[3] = "--adaptative";
	comp[4] = "--bench";
	j = 0;
	while (j < 5)
	{
		i = 0;
		while ((s1[i] && comp[j][i]) && s1[i] == comp[j][i])
			i++;
		if (s1[i] == '\0' && comp[j][i] == '\0')
			return (j + 1);
		++j;
	}
	return (0);
}

long	ft_atoi_long(const char *str)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (count * size));
	return ((void *)p);
}
