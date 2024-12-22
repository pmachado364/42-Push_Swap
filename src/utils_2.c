/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:35:37 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/27 20:17:50 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

t_stack_node	*find_minimum(t_stack *stack)
{
	t_stack_node	*min_node;
	t_stack_node	*current;

	if (!stack || !stack->head)
		return (NULL);
	min_node = stack->head;
	current = stack->head->next;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack_node	*find_maximum(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*max_node;

	current = stack->head;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

void	move_elem_to_top_a(t_stack *stack_a, t_stack_node *node,
							t_cmd_list *cmd)
{
	if (!node)
		return ;
	while (stack_a->head != node)
	{
		if (node->above_median)
			rx(stack_a, "ra", cmd);
		else
			rrx(stack_a, "rra", cmd);
	}
}

void	move_elem_to_top_b(t_stack *stack_b, t_stack_node *node,
							t_cmd_list *cmd)
{
	if (!node)
		return ;
	while (stack_b->head != node)
	{
		if (node->above_median)
			rx(stack_b, "rb", cmd);
		else
			rrx(stack_b, "rrb", cmd);
	}
}
