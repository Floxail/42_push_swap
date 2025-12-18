/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:00:00 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/18 14:02:22 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_but_three(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	while (size > 3)
	{
		pb(b, a);
		size--;
	}
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
