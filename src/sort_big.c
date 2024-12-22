/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:05:12 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/30 17:25:06 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	ft_sort_big(t_stack *stack_a, t_stack *stack_b,
						t_cmd_list *cmd)
{
	px(stack_a, stack_b, "pb", cmd);
	px(stack_a, stack_b, "pb", cmd);
	while (stack_a->size > 3)
	{
		ft_prep_moves_a(stack_a, stack_b);
		ft_move_a_to_b(stack_a, stack_b, cmd);
	}
	if (!sorted_or_not(stack_a))
		ft_sort_three(stack_a, cmd);
	while (stack_b->head)
	{
		ft_prep_moves_b(stack_b, stack_a);
		ft_move_b_to_a(stack_b, stack_a, cmd);
	}
	current_index(stack_a);
	ft_min_on_top(stack_a, cmd);
}

void	ft_min_on_top(t_stack *stack, t_cmd_list *cmd)
{
	t_stack_node	*min_node;

	min_node = find_minimum(stack);
	if (!min_node)
		return ;
	while (stack->head != min_node)
	{
		if (min_node->above_median)
			rx(stack, "ra", cmd);
		else
			rrx(stack, "rra", cmd);
	}
}

void	ft_move_b_to_a(t_stack *stack_b, t_stack *stack_a, t_cmd_list *cmd)
{
	t_stack_node	*target_node;

	target_node = stack_b->head->target_node;
	if (!stack_b->head || !target_node)
		return ;
	move_elem_to_top_a(stack_a, target_node, cmd);
	px(stack_b, stack_a, "pa", cmd);
}
