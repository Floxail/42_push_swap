/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:46:29 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/10 07:49:08 by flvejux          ###   ########.ch       */
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
	if (pos <= (size / 2))
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	pos;

	pos = find_smallest(*a);
	to_the_top(a, pos, size);
	pb(b, a);
	size--;
	pos = find_smallest(*a);
	to_the_top(a, pos, size);
	pb(b, a);
	size--;
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
