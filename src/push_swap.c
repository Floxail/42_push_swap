/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:38:33 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/23 08:38:33 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b, size);
	else
		sort_turk(a, b);
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
	int		*numbers;
	int		count;
	int		do_free;

	if (!check_entry(ac, av))
		return (0);
	numbers = parse_and_convert(ac, av, &count, &do_free);
	if (!numbers)
		return (write(2, "Error\n", 6), 1);
	stack_a = create_stack(numbers, count);
	stack_b = NULL;
	free(numbers);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	sort_and_clean(&stack_a, &stack_b, get_stack_size(stack_a));
	return (0);
}
