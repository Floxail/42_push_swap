/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 07:49:49 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/18 14:01:59 by flox             ###   ########.fr       */
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
