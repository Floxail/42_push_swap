/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:45:28 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/08 08:45:28 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// STRUCT
t_stack	*create_node(int nbr);
t_stack	*add_front(t_stack *stack, t_stack *new);
t_stack	*add_back(t_stack *stack, t_stack *new);
t_stack	*create_stack(int *tab, int size);
void	free_stack(t_stack *stack);

// OPÉRATION
void	push(t_stack **stack_give, t_stack **stack_receive);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//PARSING
int		check_entry(int ac, char **av);
int		is_valid(int ac, char **av);
int		chk_num(char *str);
int		chk_double(int *nbr, int size);
char	**extract(int ac, char **av, int *do_free);
int		count_args(char **tab);
int		*convert(char **tab, int count);
int		*parse_and_convert(int ac, char **av, int *count, int *do_free);

//SORTING
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b, int size);
void	sort_turk(t_stack **a, t_stack **b);

//UTILS
int		get_position(t_stack *stack, int value);
int		find_target_pos(t_stack *a, int value);
int		calculate_rotations(int pos, int size);
int		calculate_total_cost(t_stack *a, t_stack *b, int pos_b);
int		find_cheapest_pos(t_stack *a, t_stack *b);
void	do_rotation(t_stack **stack, int pos, int size, int is_a);
void	execute_cheapest_move(t_stack **a, t_stack **b);
void	rotate_to_min(t_stack **a);
void	ft_free_tab(char **tab);
int		is_sorted(t_stack *stack);
int		is_reverse_sorted(t_stack **stack);
int		get_stack_size(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
void	to_the_top(t_stack **a, int pos, int size);

#endif