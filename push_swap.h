/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:52:53 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/24 15:01:22 by flox             ###   ########.fr       */
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

t_stack	*create_node(int nbr);
t_stack	*add_front(t_stack *stack, t_stack *new);
t_stack	*add_back(t_stack *stack, t_stack *new);
t_stack	*create_stack(int *tab, int size);
void	free_stack(t_stack *stack);

#endif
