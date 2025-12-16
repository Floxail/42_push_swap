/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floxail <floxail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:50:18 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/16 09:13:34 by floxail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_indexed_numbers(int ac, char **av, int *count, int *do_free)
{
	int	*numbers;
	int	*indexed;

	numbers = parse_and_convert(ac, av, count, do_free);
	if (!numbers)
		return (NULL);
	indexed = indexing(numbers, count);
	free(numbers);
	return (indexed);
}

static int	init_stacks(t_stack **a, t_stack **b, int *indexed, int count)
{
	*a = create_stack(indexed, count);
	*b = NULL;
	free(indexed);
	if (!(*a))
		return (0);
	return (1);
}

static void	sort_and_clean(t_stack **a, t_stack **b, int size)
{
	sort_stack(a, b, size);
	free_stack(*a);
	free_stack(*b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*indexed;
	int		count;
	int		do_free;

	if (!check_entry(ac, av))
		return (0);
	indexed = get_indexed_numbers(ac, av, &count, &do_free);
	if (!indexed)
		return (write(2, "Error\n", 6), 1);
	if (!init_stacks(&stack_a, &stack_b, indexed, count))
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	sort_and_clean(&stack_a, &stack_b, get_stack_size(stack_a));
	return (0);
}