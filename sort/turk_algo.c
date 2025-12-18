/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:00:00 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/18 13:16:33 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_but_three(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
}

int	find_cheapest_pos(t_stack *a, t_stack *b)
{
	int	min_cost;
	int	cheapest_pos;
	int	cost;
	int	pos;
	int	size_b;

	min_cost = INT_MAX;
	cheapest_pos = 0;
	pos = 0;
	size_b = get_stack_size(b);
	while (pos < size_b)
	{
		cost = calculate_total_cost(a, b, pos);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_pos = pos;
		}
		pos++;
	}
	return (cheapest_pos);
}

void	do_rotation(t_stack **stack, int pos, int size, int is_a)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (is_a)
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (pos++ < size)
		{
			if (is_a)
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	execute_cheapest_move(t_stack **a, t_stack **b)
{
	int		cheapest_pos;
	int		target_pos;
	t_stack	*tmp;
	int		i;

	cheapest_pos = find_cheapest_pos(*a, *b);
	tmp = *b;
	i = 0;
	while (i < cheapest_pos)
	{
		tmp = tmp->next;
		i++;
	}
	target_pos = find_target_pos(*a, tmp->value);
	do_rotation(b, cheapest_pos, get_stack_size(*b), 0);
	do_rotation(a, target_pos, get_stack_size(*a), 1);
	pa(b, a);
}

void	rotate_to_min(t_stack **a)
{
	int	min_pos;
	int	size;

	min_pos = get_position(*a, find_smallest(*a)->value);
	size = get_stack_size(*a);
	do_rotation(a, min_pos, size, 1);
}

void	sort_turk(t_stack **a, t_stack **b)
{
	if (get_stack_size(*a) == 2)
		sa(a);
	else if (get_stack_size(*a) == 3)
		sort_three(a);
	else
	{
		push_all_but_three(a, b);
		sort_three(a);
		while (*b)
			execute_cheapest_move(a, b);
		rotate_to_min(a);
	}
}
