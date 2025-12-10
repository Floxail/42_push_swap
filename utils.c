/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:07:02 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/10 09:07:02 by flvejux          ###   ########.ch       */
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
