/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:46:23 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/08 08:46:47 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_entry(int ac, char **av)
{
	if (ac < 2)
		return (FALSE);
	if (ac == 2 && !av[1][0])
		return (FALSE);
	return (TRUE);
}

int	split_args(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!chk_num(split[i]))
		{
			ft_free_tab(split);
			return (FALSE);
		}
		i++;
	}
	ft_free_tab(split);
	return (TRUE);
}

int	is_valid(int ac, char **av)
{
	int		i;
	char	**split;

	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (0);
		return (split_args(split));
	}
	i = 1;
	while (i < ac)
	{
		if (!chk_num(av[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	chk_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!(str[i]))
			return (FALSE);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	chk_double(int *nbr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbr[i] == nbr[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
