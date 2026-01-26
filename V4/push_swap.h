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
	int		*tab;
	size_t	size;
	size_t	simple;
	size_t	medium;
	size_t	complex;
	size_t	adaptive;
	size_t	bench;
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
}	t_tab;

typedef struct s_buffer
{
	char	str[BUF_SIZE];
	int		len;
	int		total_written;
}	t_buffer;

void	free_all(char **args, t_tab *a, t_tab *b);

size_t	is_flag(char *s);

void	ft_printf(const char *s, ...);

size_t	number_of_args(char **args);

int		is_integer(const char *s);

size_t	find_number_of_int(char **args);

void	move_use(size_t move, t_tab *a, float metric);

void	set_table(char **args, t_tab *a);

int		is_valid_int(const char *s);
void	is_duplicate(t_tab *a, size_t size);
int		find_index(int nb, size_t size, int *buffer);
void	indexing(t_tab *a, size_t size);

void	print_error();

void	ft_free_tab(char **tab);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char const *s1, char set);

size_t	count_args(int argc, char **argv);
char	**fill_args(char **args, char **split, size_t *k);
char	**parsing(int argc, char **argv);

long	ft_atoi_long(const char *str);
void	*ft_calloc(size_t count, size_t size);

void    push_swap(char **args, t_tab *a, t_tab *b, size_t size);

void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	compare_flag(char *s1);

void	rotate(t_tab *stack, char *str);
void    rotate_ab(t_tab *a, t_tab *b);
void	reverse_rotate(t_tab *stack, char *str);
void    reverse_rotate_ab(t_tab *a, t_tab *b);

void    swap(t_tab *stack, char *str);
void    swap_ab(t_tab *a, t_tab *b);
void    push(t_tab *stack1, t_tab *stack2, char *str);

float   compute_disorder(t_tab *a);

void	simple_sort(t_tab *a, t_tab *b);
void	medium_sort(t_tab *a, t_tab *b, size_t size);
void	complex_sort(t_tab *a, t_tab *b, size_t size);

size_t	find_range_chunk(size_t n);
size_t	find_numbers_chunks(size_t tab_size, size_t chunk_range);
size_t	find_high_chunk(size_t chunk_pos, size_t chunk_range, size_t tab_size);
int		is_in_chunk(t_tab *a, size_t low, size_t high);
size_t	get_minimal_distance(t_tab *a, size_t pos);
void	rotate_to_top(t_tab *a, size_t pos);
void	push_to_a(t_tab *a, t_tab *b);

#endif