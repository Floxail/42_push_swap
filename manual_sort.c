/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:37:17 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/30 10:56:34 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	one;
	int	two;
	int	tre;

	one = (*stack)->value;
	two = (*stack)->next->value;
	tre = (*stack)->next->next->value;

	if (is_reverse_sorted(stack))
	{
		sa(stack);
		rra(stack);
	}
	else if (one > two && two < tre && one < tre)
		sa(stack);
	else if (one > two && two < tre)
		ra(stack);
	else if (one < two && one < tre && two > tre)
	{
		sa(stack);
		ra(stack);
	}
	else if (one < two && two > tre)
		rra(stack);

}

void	sort_five(t_stack **stack)
{
	int	size;
	
	size = ft_lstsize(stack);
	while (size--)
	{
		if ((*stack->value))
	}
}
