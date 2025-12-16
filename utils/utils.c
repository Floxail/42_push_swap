/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floxail <floxail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:07:02 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/16 11:01:37 by floxail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (TRUE);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	is_reverse_sorted(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return (TRUE);
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	get_stack_size(t_stack *stack)
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

int	find_max_pos(t_stack *stack)
{
	int		max_val;
	int		max_pos;
	int		pos;
	t_stack	*tmp;

	max_val = stack->value;
	max_pos = 0;
	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max_val)
		{
			max_val = tmp->value;
			max_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (max_pos);
}
