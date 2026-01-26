/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samarkar <samarkar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:52:01 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 14:28:42 by samarkar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUF_SIZE
#  define BUF_SIZE 100
# endif

typedef enum e_flags
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH,
}	t_flags;

typedef struct s_tab
{
	int		*a;
	size_t	size_a;
	int		*b;
	size_t	size_b;
}	t_tab;

typedef struct s_buffer
{
	char	str[BUF_SIZE];
	int		len;
}	t_buffer;

typedef struct s_data
{
	size_t	size;
	size_t	flag1;
	size_t	flag2;
	size_t	nb_flag;
	int		value;
}	t_data;

typedef struct s_move
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_move;

void	ft_printf(const char *s, ...);
bool	is_flag(char *s, t_data *data);
int		is_valid_int(const char *s, t_data *data);
bool	is_duplicate(t_tab *tab, int value, size_t size);
void	bench(t_data *data, t_move *move, float metric);
bool	indexing(t_tab *tab, t_data *data);
void	ft_free_tab(char **tab);
char	**ft_split(char const *s, char c, t_data *data);
bool	parsing(int argc, char **argv, t_data *data, t_tab *tab);
long	ft_atoi_long(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
bool	push_swap(t_tab *tab, t_move *move, t_data *data);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		count_flag(t_data *data, char **args);
char	*ft_strdup(const char *s1);
void	swap(t_tab *tab, char c);
void	push_a(t_tab *tab);
void	push_b(t_tab *tab);
void	rotate_a(t_tab *tab);
void	rotate_b(t_tab *tab);
void	reverse_rotate_a(t_tab *tab);
void	reverse_rotate_b(t_tab *tab);
void	simple_sort(t_tab *tab, t_move *move);
void	medium_sort(t_tab *tab, t_move *move, size_t size);
void	complex_sort(t_tab *tab, t_move *move, size_t size);
size_t	find_range_chunk(size_t n);
size_t	find_numbers_chunks(size_t tab_size, size_t chunk_range);
size_t	find_high_chunk(size_t chunk_pos, size_t chunk_range, size_t tab_size);
int		is_in_chunk(t_tab *tab, size_t low, size_t high);
size_t	get_minimal_distance(size_t size, size_t pos);
void	push_to_a(t_tab *tab, t_move *move);

#endif