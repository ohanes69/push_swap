/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:52:01 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/17 17:59:52 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_tab
{
	int		*tab;
	size_t	size;
}	t_tab;

void	set_tab(size_t strategy, t_tab *a, char **args, size_t size);
void	print_error(void);

void	ft_free_tab(char **tab);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char const *s1, char set);

size_t	count_args(int argc, char **argv);
char	**fill_args(char **args, char **split, size_t *k);
char	**parsing(int argc, char **argv);

long	ft_atoi_long(const char *str);
void	*ft_calloc(size_t count, size_t size);

void	push_swap(char **args, t_tab *a, t_tab *b, size_t size);

void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strcmp(char *s1);

void	rotate(t_tab *stack, char *str);
void	rotate_ab(t_tab *a, t_tab *b);
void	reverse_rotate(t_tab *stack, char *str);
void	reverse_rotate_ab(t_tab *a, t_tab *b);

void	swap(t_tab *stack, char *str);
void	swap_ab(t_tab *a, t_tab *b);
void	push(t_tab *stack1, t_tab *stack2, char *str);

float	compute_disorder(t_tab *a);

void	simple_sort(t_tab *a, t_tab *b);
void	medium_sort(t_tab *a, t_tab *b, size_t size);
void	complex_sort(t_tab *a, t_tab *b, size_t size);

size_t	find_range_chunk(size_t n);
size_t	find_numbers_chunks(size_t tab_size, size_t chunk_range);
size_t	find_high_chunk(size_t chunk_pos, size_t chunk_range, size_t tab_size);

void	push_to_a(t_tab *a, t_tab *b);

void	push_all_chunks_to_b(size_t tab_size, t_tab *a, t_tab *b);

int		is_in_chunk(t_tab *a, size_t low, size_t high);
size_t	get_minimal_distance(t_tab *a, size_t pos);
void	rotate_to_top(t_tab *a, size_t pos);
void	strategy_selector(size_t strategy, size_t size, t_tab *a, t_tab *b);

#endif