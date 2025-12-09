/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 29/11/2025 10:29:48 by flvejux           #+#    #+#             */
/*   Updated: 09/12/2025 08:39:46 by flvejux          ###   ########.ch       */
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


