/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floxail <floxail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2010/12/20 10:15:51 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/16 11:04:43 by floxail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int total)
{
	if (total <= 100)
		return (total / 5);
	else
		return (total / 11);
}

int	*copy_tab(int *tab, int count)
{
	int	i;
	int	*tmp;

	tmp = malloc(sizeof(int) * count);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tmp[i] = tab[i];
		i++;
	}
	return (tmp);
}

void	sorting(int *tab, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	findex(int value, int *sorted, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	*indexing(int *tab, int count)
{
	int	i;
	int	*index;
	int	*tmp;

	tmp = copy_tab(tab, count);
	if (!tmp)
		return (free (tmp), NULL);
	sorting(tmp, count);
	index = malloc(sizeof(int) * count);
	if (!index)
		return (NULL);
	i = 0;
	while (i < count)
	{
		index[i] = findex(tab[i], tmp, count);
		i++;
	}
	free (tmp);
	return (index);
}
