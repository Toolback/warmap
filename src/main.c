/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:10:49 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/15 15:28:58 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	small_sort(t_stack *stacks[2], int ac)
{
	if (ac == 2)
		sort_two_values(&stacks[A]);
	if (ac == 3)
		sort_three_values(&stacks[A]);
	if (ac == 4)
		sort_four_values(stacks);
	if (ac == 5)
		sort_five_values(stacks);
}

void	grrr(t_stack *stacks[2], char **values, int ac)
{
	parse_stack_a(&stacks[A], ac, values);
	stacks[B] = NULL;
	if (ac <= 5)
		small_sort(stacks, ac);
	if (ac > 5)
		big_sort(stacks, ac);
}

t_stack	*copy_list(t_stack *list)
{
	t_stack	*copy = NULL;
	t_stack	*curr_node = NULL;
	t_stack	*new_node = NULL;
	t_stack	*copy_node = NULL;

	curr_node = list;
	while (curr_node != NULL)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->num = curr_node->num;
		new_node->next = NULL;
		if (copy == NULL)
			copy = new_node;
		else
		{
			copy_node = copy;
			while (copy_node->next != NULL)
			{
				copy_node = copy_node->next;
			}
			copy_node->next = new_node;
		}
		curr_node = curr_node->next;
	}
	return (copy);
}

int	get_prev_count(t_stack *stack)
{
	int		count;
	t_stack	*save;

	count = 0;
	if (!stack)
	{
		ft_printf("get_prev_count: stack is null\n");
		return (-1);
	}
	save = stack;
	while (save->prev)
	{
		save = save->prev;
		count++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	t_stack	*stacks[2];
	char	**values;

	if (ac > 1)
	{
		if (ac == 2)
		{
			values = ft_split(av[1], ' ');
			ac = ft_strarrlen(values);
		}
		else
		{
			values = av + 1;
			ac = ac - 1;
		}
		if (has_duplicates(ac, values) == -1)
			error_exit("Error : Has at least twice same number\n");
		else
			grrr(stacks, values, ac);
	}
	else
		error_exit("Invalid Args Format, should be -> [./pushswap 1 3 2 4 6]");
	print_res(stacks);
	return (0);
}
