/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:52:53 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/12 10:42:20 by flvejux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include "./utils/libft/libft.h"
# include "./utils/ft_printf/ft_printf.h"

typedef struct s_stack
{
	void			*index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#endif
