/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 09/12/2025 08:40:16 by flvejux           #+#    #+#             */
/*   Updated: 09/12/2025 08:40:16 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	t_stack *tmp;
	int		mini;
	int		pos;
	int		i;

	tmp = stack;
	mini = stack->value;
	pos = 0;
	i = 0;
	while(tmp)
	{
		if (tmp->value < mini)
		{
			mini = stack->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos)
}
void	to_the_top(t_stack **a, int pos, int size)
{
	if (pos <= (size / 2))
		while (pos-- > 0)
			ra(a);
	else
		while (pos ++ < size)
			rra(a);
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	pos;

	pos = find_smallest(*a);
	to_the_top(a, pos, size);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}