/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:43:43 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/10 08:44:04 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cleanup_all(char **args, int *numbers, int do_free)
{
	if (numbers)
		free(numbers);
	if (do_free && args)
		ft_free_tab(args);
}

static int	*parse_and_convert(int ac, char **av, int *count, int *do_free)
{
	char	**args;
	int		*numbers;

	args = extract(ac, av, do_free);
	if (!args)
		return (NULL);
	*count = count_args(args);
	numbers = convert(args, *count);
	if (!numbers)
	{
		if (*do_free)
			ft_free_tab(args);
		return (NULL);
	}
	if (!chk_double(numbers, *count))
	{
		cleanup_all(args, numbers, *do_free);
		return (NULL);
	}
	if (*do_free)
		ft_free_tab(args);
	return (numbers);
}

static int	get_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

static void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b, size);
	// else
	// 	sort_big(a, b, size);
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
	sort_stack(&stack_a, &stack_b, get_stack_size(stack_a));
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
