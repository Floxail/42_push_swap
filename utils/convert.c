/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floxail <floxail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:25:23 by flvejux           #+#    #+#             */
/*   Updated: 2025/12/16 09:24:21 by floxail          ###   ########.fr       */
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

static void	cleanup_all(char **args, int *numbers, int do_free)
{
	if (numbers)
		free(numbers);
	if (do_free && args)
		ft_free_tab(args);
}