/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_revrotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:32:53 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:32:56 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	ps_rotate(t_stack *stack, int print)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->prev = stack->down;
	stack->down->next = tmp;
	stack->down = tmp;
	stack->top->prev = NULL;
	stack->down->next = NULL;
	if (stack->name == 'a' && print)
		ft_putstr("ra\n");
	else if (stack->name == 'b' && print)
		ft_putstr("rb\n");
}

void	ps_rrotate(t_stack *stack_a, t_stack *stack_b, int print)
{
	ps_rotate(stack_a, print);
	ps_rotate(stack_b, print);
}

void	ps_revrotate(t_stack *stack, int print)
{
	t_node *tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->down;
	stack->down = stack->down->prev;
	stack->down->next = NULL;
	tmp->next = stack->top;
	stack->top->prev = tmp;
	stack->top = tmp;
	stack->top->prev = NULL;
	if (stack->name == 'a' && print)
		ft_putstr("rra\n");
	else if (stack->name == 'b' && print)
		ft_putstr("rrb\n");
}

void	ps_rrevrotate(t_stack *stack_a, t_stack *stack_b, int print)
{
	ps_revrotate(stack_a, print);
	ps_revrotate(stack_b, print);
}
