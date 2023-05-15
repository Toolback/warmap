/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:33:25 by jurenaul          #+#    #+#             */
/*   Updated: 2023/03/14 12:26:55 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort(t_stack **stack, int ac)
{
	int		i;
	int		res;
	int		temp;
	t_stack	*save;

	i = 0;
	res = 1;
	temp = 0;
	save = *stack;
	while (i < ac)
	{
		if (save->next)
		{
			if (save->num > save->next->num)
			{
				temp = save->num;
				save->num = save->next->num;
				save->next->num = temp;
				res = 0;
			}
			save = save->next;
		}
		i++;
	}
	if (!res)
		sort(stack, ac);
}

t_stack	*get_min_value(t_stack *tail)
{
	t_stack	*save;
	t_stack	*min;

	save = tail;
	while (save)
	{
		if (min->num > save->num)
			min = save;
		save = save->next;
	}
	return (min);
}

int	has_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*values;

	i = 1;
	j = 0;
	values = (int *) ft_calloc(argc - 1, sizeof(int));
	if (values == NULL)
	{
		ft_printf("Values (has_duplicate) Alloc Error");
	}
	while (i < argc)
	{
		values[i - 1] = ft_atoi(argv[i]);
		while (j < i - 1)
		{
			if (values[j] == values[i - 1])
			{
				free(values);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free(values);
	return (0);
}

// Fonction pour afficher une erreur et quitter le programme
void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	print_res(t_stack *stacks[2])
{
	int	sizeA = lst_size(stacks[A]);
	int	sizeB = lst_size(stacks[B]);
	int	size;
	int	i;
	int flag;

	i = 0;
	flag = 0;
	size = sizeA > sizeB ? sizeA : sizeB;
	ft_printf("\n\nReturned Stacks :\n");
	ft_printf("---\n");
	while (i < size)
	{
		if (i < sizeA)
		{
			ft_printf("%d ", stacks[A]->num);
			if (stacks[A]->next)
			{
				if (stacks[A]->num > stacks[A]->next->num)
					flag = 1;
			}
			stacks[A] = stacks[A]->next;
		}
		else
			ft_printf("  ");
		if (i < sizeB)
		{
			ft_printf("%d\n", stacks[B]->num);
			stacks[B] = stacks[B]->next;
		}
		else
			printf("\n");
		i++;
	}
	ft_printf("---\n");
	ft_printf("A B\n");
	if (flag)
		printf("\033[31mError : Final List Not Sorted\033[0m\n");
	else
		printf("\033[32mSucces <3 Final List Sorted !\033[0m\n");

}
