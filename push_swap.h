/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:05:50 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/10 09:05:50 by flvejux          ###   ########.ch       */
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

// char
char	**extract(int ac, char **av, int *do_free);

#endif
