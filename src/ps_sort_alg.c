/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:33:06 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:33:14 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		count_cost(t_stack *a, t_node *node)
{
	t_node	*temp;
	int		move_up;

	move_up = 0;
	temp = a->top;
	if (node->data > a->max || node->data < a->min)
		while (temp->data != a->min)
		{
			move_up++;
			temp = temp->next;
		}
	else
	{
		temp = temp->next;
		while (temp && ((node->data > temp->data)
			|| (node->data < temp->prev->data)))
		{
			move_up++;
			temp = temp->next;
		}
	}
	if (ABS(a->size - move_up) < ABS(move_up))
		return (move_up - a->size);
	else
		return (move_up);
}

t_node			*get_min_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min_cost;
	t_node	*temp;
	t_node	*node_min_cost;

	i = 0;
	min_cost = stack_b->size + stack_a->size;
	temp = stack_b->top;
	node_min_cost = stack_b->top;
	while (i++ < stack_b->size)
	{
		temp->cost = count_cost(stack_a, temp);
		if (temp->index > (stack_b->size + 1) / 2)
			temp->index = temp->index - stack_b->size;
		if (ABS(temp->cost) + ABS(temp->index) < min_cost)
		{
			node_min_cost = temp;
			min_cost = ABS(temp->cost) + ABS(temp->index);
		}
		temp = temp->next;
	}
	return (node_min_cost);
}

static void		move_on_top_node_min_cost(t_stack *a, t_stack *b,
		t_node *node_min_cost)
{
	while (b->top != node_min_cost)
	{
		if (node_min_cost->index >= 0)
		{
			if (node_min_cost->cost-- > -1)
				ps_rrotate(a, b, 1);
			else
				ps_rotate(b, 1);
		}
		else
		{
			if (node_min_cost->cost++ < 0)
				ps_rrevrotate(a, b, 1);
			else
				ps_revrotate(b, 1);
		}
	}
}

static void		move_on_top_a_better_node(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top->data < stack_a->min || stack_b->top->data > stack_a->max)
		while (stack_a->top->data != stack_a->min)
		{
			if (get_max_min(stack_a, 1)->index < stack_a->size / 2)
				ps_rotate(stack_a, 1);
			else
				ps_revrotate(stack_a, 1);
		}
	else
		while (stack_a->top->data < stack_b->top->data
		|| stack_a->down->data > stack_b->top->data)
		{
			if (stack_b->top->cost >= 0)
				ps_rotate(stack_a, 1);
			else
				ps_revrotate(stack_a, 1);
		}
}

void			sorting_rise(t_stack *stack_a, t_stack *stack_b)
{
	t_node *node_min_cost;

	if (check_order(stack_a) != 0)
		ps_swap(stack_a, 1);
	while (stack_b->top)
	{
		node_min_cost = get_min_cost(stack_a, stack_b);
		move_on_top_node_min_cost(stack_a, stack_b, node_min_cost);
		move_on_top_a_better_node(stack_a, stack_b);
		ps_push(stack_b, stack_a, 1);
		mark_stack(stack_a);
		mark_stack(stack_b);
	}
}
