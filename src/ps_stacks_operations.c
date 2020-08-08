/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:33:24 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:33:27 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_max_min(t_stack *stack, int is_max)
{
	t_node *max;
	t_node *min;
	t_node *node;

	node = stack->top;
	max = stack->down;
	min = stack->down;
	while (node)
	{
		if (node->data > max->data)
			max = node;
		else if (node->data < min->data)
			min = node;
		node = node->next;
	}
	if (is_max)
		return (max);
	else
		return (min);
}

void	mark_stack(t_stack *stack)
{
	int		i;
	t_node	*node;

	if (!stack->top)
		return ;
	i = 0;
	node = stack->top;
	while (node->next)
	{
		node->index = i++;
		node = node->next;
	}
	stack->down = node;
	stack->down->index = i;
	stack->size = i + 1;
	node = stack->top;
	while (node->next && node->index != stack->size / 2)
		node = node->next;
	stack->max = get_max_min(stack, 1)->data;
	stack->min = get_max_min(stack, 0)->data;
}

int		check_order(t_stack *stack)
{
	t_node	*min;
	t_node	*node;
	int		min_val;
	int		i;

	i = 0;
	min = get_max_min(stack, 0);
	min_val = min->data;
	node = min->next ? min->next : stack->top;
	while (i++ < stack->size)
	{
		if (node->data < min->data && node->data != min_val)
			return (-1);
		node = node->next ? node->next : stack->top;
		min = min->next ? min->next : stack->top;
	}
	return (0);
}

int		check_sort(t_stack *stack)
{
	t_node *node;

	if (stack->size == 1)
		return (1);
	node = stack->top;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}
