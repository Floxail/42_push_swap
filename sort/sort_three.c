/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 07:49:49 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/10 07:49:59 by flvejux          ###   ########.ch       */
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
