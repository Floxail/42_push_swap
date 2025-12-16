/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:46:05 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/16 17:37:30 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_give, t_stack **stack_receive)
{
	t_stack	*tmp;

	if (!stack_give || !*stack_give)
		return ;
	tmp = *stack_give;
	*stack_give = (*stack_give)->next;
	if (*stack_give)
		(*stack_give)->prev = NULL;
	tmp->next = *stack_receive;
	tmp->prev = NULL;
	if (*stack_receive)
		(*stack_receive)->prev = tmp;
	*stack_receive = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **b, t_stack **a)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
