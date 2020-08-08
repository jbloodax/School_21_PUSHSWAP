/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:31:20 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:31:32 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	middle_el(t_node *stack)
{
	int i;
	int middle;

	i = 0;
	middle = len_list(stack) / 2;
	while (i++ < middle)
		stack = stack->next;
	return (stack->data);
}

static void	split_respecting_median(t_node *node, t_node **under_median,
		t_node **over_median, t_node **median)
{
	*under_median = NULL;
	*over_median = NULL;
	(*median)->data = middle_el(node);
	while (node)
	{
		if (node->data != (*median)->data)
		{
			if (node->data >= (*median)->data)
				add_node_in_start(node->data, over_median);
			else
				add_node_in_start(node->data, under_median);
		}
		node = node->next;
	}
}

t_node		*get_median(t_node *stack, int pos, t_node *median)
{
	t_node *under_median;
	t_node *over_median;

	split_respecting_median(stack, &under_median, &over_median, &median);
	if (pos != len_list(under_median) + 1)
		median->data = len_list(under_median) >= pos
				? get_median(under_median, pos, median)->data
				: get_median(over_median, pos - len_list(stack)
				+ len_list(over_median), median)->data;
	delete_list(&under_median);
	delete_list(&over_median);
	return (median);
}
