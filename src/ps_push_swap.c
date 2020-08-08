/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:32:37 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:32:41 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	ps_push(t_stack *stack_from, t_stack *stack_to, int print)
{
	t_node *temp;

	if (!stack_from->top)
		return ;
	temp = stack_from->top->next;
	stack_from->top->next = stack_to->top;
	if (temp)
		temp->prev = NULL;
	if (stack_to->top)
		stack_to->top->prev = stack_from->top;
	stack_to->top = stack_from->top;
	stack_from->top = temp;
	if (stack_to->name == 'a' && print)
		ft_putstr("pa\n");
	else if (stack_to->name == 'b' && print)
		ft_putstr("pb\n");
}

void	ps_swap(t_stack *stack, int print)
{
	t_node	*first;
	t_node	*second;
	t_node	*first_prev;
	t_node	*third;

	if (stack->top && (stack->top)->next)
	{
		first = stack->top;
		second = (stack->top)->next;
		third = (stack->top)->next->next;
		first_prev = (stack->top)->prev;
		first->next = third;
		first->prev = second;
		second->next = first;
		second->prev = first_prev;
		if (third)
			third->prev = first;
		stack->top = second;
	}
	if (stack->name == 'a' && print)
		ft_putstr("sa\n");
	else if (stack->name == 'b' && print)
		ft_putstr("sb\n");
}
