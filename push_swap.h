/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floxail <floxail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:05:50 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/16 11:00:04 by floxail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include "./utils/libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// struct
t_stack	*create_node(int nbr);
t_stack	*add_front(t_stack *stack, t_stack *new);
t_stack	*add_back(t_stack *stack, t_stack *new);
t_stack	*create_stack(int *tab, int size);

// void
void	free_stack(t_stack *stack);
void	swap(t_stack **stack);
void	ft_free_tab(char **tab);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	push(t_stack **stack_give, t_stack **stack_receive);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sa(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	to_the_top(t_stack **a, int pos, int size);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b, int size);
void	sorting(int *tab, int count);
void	push_chunk_to_b(t_stack **a, t_stack **b,
			int chunk_num, int chunk_size);
void	push_all_to_a(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b, int size);

// int 
int		check_entry(int ac, char **av);
int		is_valid(char *av);
int		chk_num(char *str);
int		chk_double(int *nbr, int size);
int		is_sorted(t_stack *stack);
int		is_reverse_sorted(t_stack **stack);
int		find_smallest(t_stack *stack);
int		count_args(char **tab);
int		*convert(char **tab, int count);
int		*copy_tab(int *tab, int count);
int		findex(int value, int *sorted, int count);
int		*indexing(int *tab, int count);
int		get_chunk_size(int total);
int		is_in_chunk(int index, int chunk_num, int chunk_size);
int		find_chunk_elem(t_stack *stack, int chunk_num, int chunk_size);
int		find_max_pos(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		*parse_and_convert(int ac, char **av, int *count, int *do_free);

// char
char	**extract(int ac, char **av, int *do_free);

#endif