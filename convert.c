/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:36:43 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/19 12:58:14 by flvejux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*extract_and_convert(int ac, char **av)
{
	int		i;
	char	**tab;
	t_stack	*a;

	a = NULL;
	i = 1;
	if (ac == 2)
	{
		*tab = ft_split(av[1], ' ');
		if (!tab)
			return (free(tab), NULL);
	}
	else if (ac > 2)
	{
		while (i < ac)
		{
			tab = av[i];
			i++;
		}
	}
	While(tab[i])
	{
		
	}
}
