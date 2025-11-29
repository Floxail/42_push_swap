/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:29:16 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/27 10:29:30 by flvejux          ###   ########.ch       */
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

void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
