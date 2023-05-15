/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:21 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/15 15:25:25 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	sort_two_values(t_stack **stack)
{
	ft_printf("TWO VALUES");
	if ((*stack)->num > (*stack)->next->num)
	{
		sa(stack, 1);
	}
	return (0);
}

int	sort_three_values_bis(t_stack **stack)
{
	ft_printf("THREEbis VALUES");
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
	{
		ra(stack, 1);
	}
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
	{
		rra(stack, 1);
	}
	return (0);
}

int	sort_three_values(t_stack **stack)
{
		ft_printf("THREE VALUES");
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
	{
		sa(stack, 1);
		printf("SA Operated ! \n");
	}
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	sort_three_values_bis(stack);
	return (0);
}

void	sort_four_values(t_stack *stacks[2])
{
	ft_printf("four VALUES");
	pb(&stacks[A], &stacks[B]);
	sort_three_values(&stacks[A]);
	if (stacks[B]->num > stacks[A]->num
		&& stacks[B]->num < stacks[A]->next->num)
	{
		pa(&stacks[A], &stacks[B]);
		sa(&stacks[A], 1);
	}
	else if (stacks[B]->num > stacks[A]->next->num
		&& stacks[B]->num < stacks[A]->next->next->num)
	{
		rra(&stacks[A], 1);
		pa(&stacks[A], &stacks[B]);
		rb(&stacks[A], 1);
		rb(&stacks[A], 1);
	}
	else if (stacks[B]->num > stacks[A]->next->next->num)
	{
		pa(&stacks[A], &stacks[B]);
		rb(&stacks[A], 1);
	}
	else
	{
		pa(&stacks[A], &stacks[B]);
	}
}

void	sort_five_values(t_stack *stacks[2])
{
	int		index;
	t_stack	*min;

	ft_printf("FIVE VALUES");
	min = get_min_value(stacks[A]);
	ft_printf("min value retrieved [%d]\n", min->num);
	index = min->get_prev_count(min);
	if (index == 1)
		sa(&stacks[A], 1);
	if (index == 2)
	{
		ra(&stacks[A], 1);
		sa(&stacks[A], 1);
	}
	if (index == 3)
	{
		rra(&stacks[A], 1);
		rra(&stacks[A], 1);
	}
	if (index == 4)
		rra(&stacks[A], 1);
	pb(&stacks[A], &stacks[B]);
	sort_four_values(&stacks[A]);
	pa(&stacks[A], &stacks[B]);
}
