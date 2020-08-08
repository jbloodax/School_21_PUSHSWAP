/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:29:44 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:34:13 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	read_instructions_3(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strequ("ss", line))
	{
		ps_swap(stack_a, 0);
		ps_swap(stack_b, 0);
	}
	else if (ft_strequ("rr", line))
	{
		ps_rotate(stack_a, 0);
		ps_rotate(stack_b, 0);
	}
	else if (ft_strequ("rrr", line))
	{
		ps_revrotate(stack_a, 0);
		ps_revrotate(stack_b, 0);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	mark_stack(stack_a);
	mark_stack(stack_b);
}

static void	read_instructions_2(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strequ("ra", line))
	{
		ps_rotate(stack_a, 0);
		mark_stack(stack_a);
	}
	else if (ft_strequ("rb", line))
	{
		ps_rotate(stack_b, 0);
		mark_stack(stack_b);
	}
	else if (ft_strequ("rra", line))
	{
		ps_revrotate(stack_a, 0);
		mark_stack(stack_a);
	}
	else if (ft_strequ("rrb", line))
	{
		ps_revrotate(stack_b, 0);
		mark_stack(stack_b);
	}
	else
		read_instructions_3(stack_a, stack_b, line);
}

static void	read_instructions(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strequ("pa", line))
	{
		ps_push(stack_b, stack_a, 0);
		mark_stack(stack_a);
		mark_stack(stack_b);
	}
	else if (ft_strequ("pb", line))
	{
		ps_push(stack_a, stack_b, 0);
		mark_stack(stack_a);
		mark_stack(stack_b);
	}
	else if (ft_strequ("sa", line))
	{
		ps_swap(stack_a, 0);
		mark_stack(stack_a);
	}
	else if (ft_strequ("sb", line))
	{
		ps_swap(stack_b, 0);
		mark_stack(stack_b);
	}
	else
		read_instructions_2(stack_a, stack_b, line);
}

static char	ft_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!*line)
			break ;
		read_instructions(stack_a, stack_b, line);
		free(line);
	}
	if (check_sort(stack_a) && stack_b->size <= 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
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
	ft_checker(stack_a, stack_b);
	clean_stack(stack_a);
	clean_stack(stack_b);
	if (av && not_str_input == 0)
		free_array(av);
	return (0);
}
