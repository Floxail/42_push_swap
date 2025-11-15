/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:30:18 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/15 10:30:46 by flvejux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_entry(int ac, char **av)
{
	if (ac != 2)
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
	}
	i++;
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
			if (str[i + 1] == '\0')
				return (FALSE);
		else if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	chk_double(int *num)
{
	int	i;
	int	j;

	i = 0;
	while (num[i])
	{
		j = i + 1;
		while (num[j])
		{
			if (num[i] == num[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
