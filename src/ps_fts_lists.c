/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fts_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:32:10 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:32:14 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*add_node_in_start(int data, t_node **first_node)
{
	t_node	*node;

	if (!*first_node)
	{
		*first_node = create_node(data);
		(*first_node)->next = NULL;
		(*first_node)->prev = NULL;
	}
	else
	{
		node = create_node(data);
		node->next = *first_node;
		node->prev = NULL;
		(*first_node)->prev = node;
		*first_node = node;
	}
	return (*first_node);
}

void	delete_list(t_node **first_node)
{
	t_node *node;

	while (*first_node)
	{
		node = (*first_node)->next;
		free(*first_node);
		*first_node = node;
	}
	*first_node = NULL;
}

int		len_list(t_node *node)
{
	int i;

	i = 0;
	while (node && ++i)
		node = node->next;
	return (i);
}
