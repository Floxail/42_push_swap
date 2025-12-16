/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:51:02 by floxail           #+#    #+#             */
/*   Updated: 2025/12/16 17:51:36 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_chunk(int index, int chunk_num, int chunk_size)
{
	int	min;
	int	max;

	min = chunk_num * chunk_size;
	max = (chunk_num + 1) * chunk_size;
	if (index >= min && index < max)
		return (1);
	return (0);
}

int	find_chunk_elem(t_stack *stack, int chunk_num, int chunk_size)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (is_in_chunk(tmp->value, chunk_num, chunk_size))
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

void	push_chunk_to_b(t_stack **a, t_stack **b, int chunk_num, int chunk_size)
{
	int	pos;
	int	mid_chunk;

	mid_chunk = (chunk_num * chunk_size) + (chunk_size / 2);
	while (1)
	{
		pos = find_chunk_elem(*a, chunk_num, chunk_size);
		if (pos == -1)
			break ;
		to_the_top(a, pos, get_stack_size(*a));
		pb(b, a);
		if ((*b)->value < mid_chunk)
			rb(b);
	}
}


void push_all_to_a(t_stack **a, t_stack **b)
{
	int pos;
	
	while (*b)
	{
		pos = find_max_pos(*b);
		to_the_top(b, pos, get_stack_size(*b));
		pa(a, b);
	}
}

void	sort_big(t_stack **a, t_stack **b, int size)
{
	int	chunk_size;
	int	nb_chunks;
	int	i;

	chunk_size = get_chunk_size(size);
	nb_chunks = size / chunk_size;
	if (size % chunk_size != 0)
		nb_chunks++;
	i = 0;
	while (i < nb_chunks)
	{
		push_chunk_to_b(a, b, i, chunk_size);
		i++;
	}
	while (*a && get_stack_size(*a) > 3)
		pb(a, b);
	if (*a && get_stack_size(*a) == 3)
		sort_three(a);
	else if (*a && get_stack_size(*a) == 2)
		sa(a);
	push_all_to_a(a, b);
}
