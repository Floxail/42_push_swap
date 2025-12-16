/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:46:29 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/16 17:31:34 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	t_stack	*tmp;
	int		mini;
	int		pos;
	int		i;

	tmp = stack;
	mini = stack->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < mini)
		{
			mini = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
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

	pos = find_smallest(*a);
	to_the_top(a, pos, size);
	pb(a, b);
	size--;
	pos = find_smallest(*a);
	to_the_top(a, pos, size);
	pb(a, b);
	size--;
	sort_three(a);
	pa(b, a);
	pa(b, a);
}
