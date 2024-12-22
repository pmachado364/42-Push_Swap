/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:24:13 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/30 15:33:50 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

static void	rotate_both(t_stack *stack_a, t_stack *stack_b,
							t_stack_node *cheapest_node, t_cmd_list *cmd)
{
	while (stack_b->head != cheapest_node->target_node
		&& stack_a->head != cheapest_node)
	{
		rr(stack_a, stack_b, cmd);
	}
	current_index(stack_a);
	current_index(stack_b);
}

static void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b,
								t_stack_node *cheapest_node, t_cmd_list *cmd)
{
	while (stack_b->head != cheapest_node->target_node
		&& stack_a->head != cheapest_node)
	{
		rrr(stack_a, stack_b, cmd);
	}
	current_index(stack_a);
	current_index(stack_b);
}

t_stack_node	*get_cheapest(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*cheapest_node;
	long			cheapest_cost;

	if (!stack || !stack->head)
		ft_end(ERROR_C_STACK);
	current = stack->head;
	cheapest_node = current;
	cheapest_cost = current->push_cost;
	while (current)
	{
		if (current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

void	ft_move_a_to_b(t_stack *stack_a, t_stack *stack_b, t_cmd_list *cmd)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(stack_a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node, cmd);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both(stack_a, stack_b, cheapest_node, cmd);
	move_elem_to_top_a(stack_a, cheapest_node, cmd);
	move_elem_to_top_b(stack_b, cheapest_node->target_node, cmd);
	px(stack_a, stack_b, "pb", cmd);
}
