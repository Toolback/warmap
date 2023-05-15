/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bis_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:31:54 by jurenaul          #+#    #+#             */
/*   Updated: 2023/03/15 16:20:10 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	rrr(t_stack **stack_A, t_stack **stack_B)
{
	if (!rra(stack_A, 0) || !rrb(stack_B, 0))
		return (0);
	ft_printf("rra\n");
	return (1);
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
int	pb(t_stack **stack_A, t_stack **stack_B)
{
	pa(stack_B, stack_A, 0);
	ft_printf("pb\n");
	return (1);
}
