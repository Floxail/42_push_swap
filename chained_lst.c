/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:38:31 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/20 08:21:18 by flvejux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_node(int nbr)
{
	t_stack *a;
	
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->value
}