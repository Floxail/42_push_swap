/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:38:31 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/24 15:00:57 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*add_front(t_stack *stack, t_stack *new)
{
	if (!new)
		return (stack);
	new->next = stack;
	if (stack)
		stack->prev = new;
	return (new);
}

t_stack	*add_back(t_stack *stack, t_stack *new)
{
	t_stack	*current;

	if (!new)
		return (stack);
	if (!stack)
		return (new);
	current = stack;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
	return (stack);
}

t_stack	*create_stack(int *tab, int size)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		new = create_node(tab[i]);
		if (!new)
			return (free_stack(stack), NULL);
		stack = add_back(stack, new);
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
