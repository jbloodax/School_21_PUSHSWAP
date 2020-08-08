/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:35:57 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 14:36:01 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define ABS(x) ((x < 0) ? -x : x)

typedef struct		s_node
{
	int				data;
	int				cost;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_stack
{
	char			name;
	t_node			*top;
	t_node			*down;
	t_node			*middle;
	int				size;
	int				max;
	int				min;
}					t_stack;

void				check_split_array(char **array, int size_array);
void				check_input_exceptions(int ac, char **av);
void				check_input_error(int ac, char **av);
int					check_args(int ac, char **av);
int					check_sort(t_stack *stack);
int					check_order(t_stack *stack);
int					count_char_into_string(char *str, char c);
t_node				*create_node(int data);
t_stack				*create_stack(char name);
void				ps_push(t_stack *stack_from, t_stack *stack_to, int print);
void				ps_swap(t_stack *stack, int print);
void				ps_rotate(t_stack *stack, int print);
void				ps_revrotate(t_stack *stack, int print);
void				ps_rrotate(t_stack *stack_a, t_stack *stack_b, int print);
void				ps_rrevrotate(t_stack *stack_a, t_stack *stack_b,
									int print);
t_node				*get_median(t_node *stack, int pos, t_node *median);
void				mark_stack(t_stack *stack);
t_node				*get_max_min(t_stack *stack, int is_max);
t_node				*add_node_in_start(int data, t_node **first_node);
void				delete_list(t_node **first_node);
int					len_list(t_node *node);
void				read_input_chain(int ac, char **av, t_stack *chain,
										int not_str);
t_node				*get_min_cost(t_stack *stack_a, t_stack *stack_b);
void				sorting_rise(t_stack *stack_a, t_stack *stack_b);
void				clean_stack(t_stack *stack);
void				print_stack_a(t_stack *stack_a);
void				free_array(char **array);

#endif
