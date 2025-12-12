/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2010/12/20 10:15:51 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/12 12:13:48 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack **stack)
{
	t_stack **a;
	t_stack **b;

}

int *indexe_stack(int *tab, int count)
{
	int	i;
	int	j;
	
	i = 0;
	while (j < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < count)
	{
		tab[i] = i;
		i++;
	}
	return (tab);
}

void