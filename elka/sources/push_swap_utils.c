/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:53:58 by lucpelle          #+#    #+#             */
/*   Updated: 2026/01/26 12:02:04 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

size_t	compare_flag(char *s1)
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
