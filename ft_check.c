/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:06:11 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/30 09:06:11 by flvejux          ###   ########.ch       */
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

int	is_valid(char *av)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(av, ' ');
	if (!tmp)
		return (FALSE);
	while (tmp[i])
	{
		if (!chk_num(tmp[i]))
			return (ft_free(tmp), FALSE);
		i++;
	}
	ft_free(tmp);
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
