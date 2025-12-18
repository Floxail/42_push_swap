/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:46:29 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/18 13:51:26 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*smallest;

	tmp = stack;
	smallest = stack;
	while (tmp)
	{
		if (tmp->value < smallest->value)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

void	to_the_top(t_stack **a, int pos, int size)
{
	int	rotation;

	if (pos <= (size / 2))
		while (pos-- > 0)
			ra(a);
	else
	{
		rotation = size - pos;
		while (rotation-- > 0)
			rra(a);
	}
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	pos;

	pos = get_position(*a, find_smallest(*a)->value);
	to_the_top(a, pos, size);
	pb(b, a);
	size--;
	pos = get_position(*a, find_smallest(*a)->value);
	to_the_top(a, pos, size);
	pb(b, a);
	size--;
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
