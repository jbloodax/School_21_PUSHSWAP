/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fts_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:32:25 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:32:28 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	free_array(char **array)
{
	int i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	print_stack_a(t_stack *stack_a)
{
	t_node	*node;
	int		i;

	mark_stack(stack_a);
	node = stack_a->top;
	i = 0;
	while (++i <= stack_a->size)
	{
		ft_putnbr(node->data);
		ft_putchar(' ');
		if (node->next)
			node = node->next;
	}
	ft_putstr("\n");
}

t_node	*create_node(int data)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (0);
	*node = (t_node){data, 0, 0, 0, 0};
	return (node);
}

t_stack	*create_stack(char name)
{
	t_stack	*stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	*stack = (t_stack){name, 0, 0, 0, 0, 0, 0};
	return (stack);
}

void	clean_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		node = node->next;
		free(stack->top);
		stack->top = node;
	}
	free(stack);
}
