/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:16:29 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 14:56:51 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../lib/Libft/libft.h"
# include "errors.h"

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	int					index;
	int					push_cost;
	bool				above_median;
	struct s_stack_node	*target_node;
}	t_stack_node;

typedef struct s_minmax
{
	int					max;
	int					min;
}	t_minmax;

typedef struct s_stack
{
	t_stack_node		*head;
	t_stack_node		*tail;
	size_t				size;
	t_minmax			*limits;
}	t_stack;

typedef struct s_cmd
{
	char			*instruction;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_cmd_list
{
	t_cmd	*head;
	t_cmd	*tail;
	int		size;
}	t_cmd_list;

/* Function prototypes */

// Parse && error check
t_stack			*ft_parse(int argc, char **argv);
void			ft_push_to_stack(t_stack *stack, int value);
t_stack			*ft_create_stack(void);
void			ft_check_duplicates(t_stack *stack);
bool			ft_check_input_errors(char **values);
bool			ft_is_single_number(const char *str);
void			ft_free_split(char ***values);
void			ft_end(char *str);

// Utils
int				ft_contains_space(const char *str);
void			ft_free_stack(t_stack *stack);
bool			sorted_or_not(t_stack *stack);
bool			reverse_sorted_or_not(t_stack *stack);
t_stack_node	*find_min_node(t_stack *stack);
t_stack_node	*find_minimum(t_stack *stack);
t_stack_node	*find_maximum(t_stack *stack);
void			move_elem_to_top_b(t_stack *stack_b, t_stack_node *node,
					t_cmd_list *cmd);
void			move_elem_to_top_a(t_stack *stack_a, t_stack_node *node,
					t_cmd_list *cmd);

// Cmd_struct
t_cmd_list		*init_command_list(void);
void			ft_add_command(t_cmd_list *list, const char *cmd);
void			ft_print_commands(t_cmd_list *list);
void			ft_free_command_list(t_cmd_list *list);

// Sorting
void			ft_sorting_stacks(t_stack *stack_a, t_stack *stack_b,
					t_cmd_list *cmd);
void			ft_sort_two(t_stack *stack, t_cmd_list *cmd);
void			ft_sort_three(t_stack *stack, t_cmd_list *cmd);
void			ft_sort_four(t_stack *a, t_stack *b, t_cmd_list *cmd);
void			ft_sort_big(t_stack *stack_a, t_stack *stack_b,
					t_cmd_list *cmd);
void			ft_prep_moves_a(t_stack *stack_a, t_stack *stack_b);
void			ft_move_a_to_b(t_stack *stack_a, t_stack *stack_b,
					t_cmd_list *cmd);
void			ft_prep_moves_b(t_stack *stack_b, t_stack *stack_a);
void			ft_move_b_to_a(t_stack *stack_b, t_stack *stack_a,
					t_cmd_list *cmd);
void			ft_min_on_top(t_stack *stack, t_cmd_list *cmd);
void			current_index(t_stack *stack);
void			find_maxmin(t_stack *stack);
void			find_max(t_stack *stack);
void			find_min(t_stack *stack);
void			cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
void			set_target_node(t_stack *stack_a, t_stack *stack_b);
void			find_target_in_b(t_stack_node *current_a, t_stack *stack_b);
t_stack_node	*get_cheapest(t_stack *stack);
void			set_target_b(t_stack *stack_b, t_stack *stack_a);
void			find_target_in_a(t_stack_node *current_b, t_stack *stack_a);

// Operations
t_stack_node	*ft_pop(t_stack *stack);
void			ft_push(t_stack *stack, t_stack_node *elem);
void			px(t_stack *from_stack, t_stack *to_stack,
					const char *name, t_cmd_list *cmd);

void			ft_swap(t_stack *stack);
void			ss(t_stack *stack_a, t_stack *stack_b, t_cmd_list *cmd);
void			sx(t_stack *stack, const char *name, t_cmd_list *cmd);

void			ft_rotate_x(t_stack *stack);
void			rx(t_stack *stack, const char *name, t_cmd_list *cmd);
void			rr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *cmd);

void			ft_rev_rotate_x(t_stack *stack);
void			rrx(t_stack *stack, const char *name, t_cmd_list *cmd);
void			rrr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *cmd);

#endif