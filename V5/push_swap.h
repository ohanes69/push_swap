/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucpelle <lucpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:52:01 by samarkar          #+#    #+#             */
/*   Updated: 2026/01/26 12:02:04 by lucpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUF_SIZE
#  define BUF_SIZE 1024
# endif

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
	size_t	move;
	size_t	bench;
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
void	move_use(t_data *data, t_move *move, float metric);
void	indexing(t_tab *tab);
void	print_error(void);
void	ft_free_tab(char **tab);
char	**ft_split(char const *s, char c, t_data *data);
t_tab	*parsing(int argc, char **argv, t_tab *tab, t_data *data);
long	ft_atoi_long(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	push_swap(t_tab *tab, t_move *move, t_data *data);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	compare_flag(char *s1);
char	*ft_strdup(const char *s1);
char	*ft_strdup2(char const *s1, char set);
void	swap(t_tab *tab, char c);
void	push_a(t_tab *tab);
void	push_b(t_tab *tab);
void	rotate_a(t_tab *tab);
void	rotate_b(t_tab *tab);
void	reverse_rotate_a(t_tab *tab);
void	reverse_rotate_b(t_tab *tab);
float	compute_disorder(t_tab *a);
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