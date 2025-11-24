/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:30:18 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/24 10:46:08 by flox             ###   ########.fr       */
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
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			if (!ft_isdigit(str[i + 1]))
				return (FALSE);
		else if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	chk_double(int *nbr)
{
	int	i;
	int	j;

	i = 0;
	while (nbr[i])
	{
		j = i + 1;
		while (nbr[j])
		{
			if (nbr[i] == nbr[j])
				return (free(nbr), FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
