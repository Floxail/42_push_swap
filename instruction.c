/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:25:25 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/25 12:36:10 by flvejux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp_first;
	t_stack	*tmp_second;
	
	if (!(*stack) || !(*stack)->next)
		return ;
	tmp_first = *stack;
	tmp_second = (*stack)->next;
	tmp_first->next = tmp_second->next;
	tmp_second->next = tmp_first;
	if (tmp_second->next)
		tmp_second->next->prev = tmp_first;
	tmp_first->prev = tmp_second;
	tmp_second->prev = NULL;
	
	*stack = tmp_second;
}

void	push(t_stack **stack_give, t_stack **stack_receive)
{
	t_stack	tmp;
	
	if (!stack_receive)
		return ;
	tmp = (*stack_give)->next;
	(*stack_receive)->next = *stack_give;
	*stack_give = *stack_receive;
	*stack_receive = tmp;	
}

void	rotate(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if (!stack || !(*stack)->next)
		return ;
	*stack = tmp->next;
	tmp->next = NULL;	

/* 	if (!stack->stack)
			return ;
		stack->stack = stack->stack->next; */
}

