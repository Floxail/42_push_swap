/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:00:00 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/18 13:16:21 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, int value)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

int	find_target_pos(t_stack *a, int value)
{
	int		target_pos;
	int		target_val;
	int		pos;
	t_stack	*tmp;

	target_val = INT_MAX;
	target_pos = 0;
	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > value && tmp->value < target_val)
		{
			target_val = tmp->value;
			target_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (target_val == INT_MAX)
		return (get_position(a, find_smallest(a)->value));
	return (target_pos);
}

int	calculate_rotations(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

int	calculate_total_cost(t_stack *a, t_stack *b, int pos_b)
{
	int		size_a;
	int		size_b;
	int		target_a;
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;
	int		i;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	tmp = b;
	i = 0;
	while (i < pos_b)
	{
		tmp = tmp->next;
		i++;
	}
	target_a = find_target_pos(a, tmp->value);
	cost_a = calculate_rotations(target_a, size_a);
	cost_b = calculate_rotations(pos_b, size_b);
	return (cost_a + cost_b);
}
