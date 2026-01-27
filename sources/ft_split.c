/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:55:45 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/27 13:47:53 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static size_t	is_charset(char c, char set)
{
	if (c == set)
		return (0);
	return (1);
}

static char	*ft_strdup_split(char const *s1, char set)
{
	size_t		i;
	size_t		len;
	char		*copy;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != set)
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	len = i;
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

char	**ft_split(char const *s, char c, t_data *data)
{
	char		**tab;
	size_t		i;

	data->size = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (data->size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < data->size)
	{
		while (*s != '\0' && is_charset(*s, c) == 0)
			s++;
		tab[i] = ft_strdup_split(s, c);
		if (!tab[i])
		{
			ft_free_tab(tab);
			return (NULL);
		}
		while (*s != '\0' && is_charset(*s, c) == 1)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
