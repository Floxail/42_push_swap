/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:36:43 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/25 08:25:31 by flvejux          ###   ########.fr       */
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
		if (tmp < INT_MAX || tmp > INT_MAX)
		{
			free(nbr);
			return (NULL);
		}
		i++;
		nbr[i] = (int)tmp;
	}
	return (nbr);
}
