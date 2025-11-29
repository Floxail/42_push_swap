/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:16:38 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/29 09:07:21 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack *b_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	b_last = last->prev;
	b_last->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
}
