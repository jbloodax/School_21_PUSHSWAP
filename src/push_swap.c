/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:34:04 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:34:07 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_input_chain(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_node	*median;

	i = 0;
	median = create_node(0);
	median = get_median(stack_a->top, (stack_a->size) / 2, median);
	while (i++ < stack_a->size)
	{
		if (stack_a->top->data <= median->data)
		{
			ps_push(stack_a, stack_b, 1);
			mark_stack(stack_b);
		}
		else
		{
			if (stack_b->top && stack_b->top->data
			< (stack_b->max + stack_b->min) / 2)
				ps_rrotate(stack_a, stack_b, 1);
			else
				ps_rotate(stack_a, 1);
		}
	}
	free(median);
	mark_stack(stack_a);
}

static void	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	t_node *node;

	node = stack_a->top;
	if (check_sort(stack_a))
		exit(0);
	if (stack_a->size == 2 && node->data > node->next->data)
	{
		ps_swap(stack_a, 1);
		exit(0);
	}
	while (stack_a->size > 3)
		split_input_chain(stack_a, stack_b);
	sorting_rise(stack_a, stack_b);
	while (stack_a->top->data != stack_a->min)
		if (ABS(stack_a->top->data - stack_a->min)
			> ABS(stack_a->down->data - stack_a->min))
			ps_revrotate(stack_a, 1);
		else
			ps_rotate(stack_a, 1);
}

int			main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char	**array_args;
	int		not_str_input;

	not_str_input = 1;
	array_args = NULL;
	check_input_exceptions(ac, av);
	if (ac == 2)
	{
		ac = count_char_into_string(av[1], ' ') + 1;
		array_args = ft_strsplit(av[1], ' ');
		av = array_args;
		not_str_input = 0;
		check_split_array(av, ac);
	}
	check_input_error(ac, av);
	stack_a = create_stack('a');
	stack_b = create_stack('b');
	read_input_chain(ac, av, stack_a, not_str_input);
	ft_push_swap(stack_a, stack_b);
	clean_stack(stack_a);
	clean_stack(stack_b);
	if (av && not_str_input == 0)
		free_array(av);
	return (0);
}
