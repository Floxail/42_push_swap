/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:25:23 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/29 09:26:05 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**extract(int ac, char **av, int *do_free)
{
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			return (NULL);
		*do_free = 1;
	}
	else if (ac > 2)
	{
		tab = av + 1;
		*do_free = 0;
	}
	return (tab);
}

int	count_args(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int	*convert(char **tab, int count)
{
	long	tmp;
	int		*nbr;
	int		i;

	i = 0;
	nbr = malloc(sizeof(int) * count);
	if (!nbr)
		return (NULL);
	while (count > i)
	{
		tmp = ft_atol(tab[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			free(nbr);
			return (NULL);
		}
		nbr[i] = (int)tmp;
		i++;
	}
	return (nbr);
}
