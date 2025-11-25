/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:52:53 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/25 09:34:12 by flvejux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include "./utils/libft/libft.h"
# include "./utils/ft_printf/ft_printf.h"
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
void ft_free(char **tab);

// int 
int	check_entry(int ac, char **av);
int	is_valid(char *av);
int	chk_num(char *str);
int	chk_double(int *nbr, int size);

#endif
