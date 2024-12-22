/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_moves_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:23:09 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/30 15:34:18 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	current_index(t_stack *stack)
{
	t_stack_node	*current_node;
	int				i;
	int				median;

	if (!stack || !stack->head)
		ft_end(ERROR_C_STACK);
	current_node = stack->head;
	i = 0;
	median = stack->size / 2;
	while (current_node)
	{
		current_node->index = i;
		current_node->above_median = (i <= median);
		current_node = current_node->next;
		++i;
	}
}

void	find_target_in_b(t_stack_node *current_a, t_stack *stack_b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_value;

	current_b = stack_b->head;
	target_node = NULL;
	best_match_value = LONG_MIN;
	while (current_b)
	{
		if (current_b->value < current_a->value
			&& current_b->value > best_match_value)
		{
			best_match_value = current_b->value;
			target_node = current_b;
		}
		current_b = current_b->next;
	}
	if (!target_node)
		current_a->target_node = find_maximum(stack_b);
	else
		current_a->target_node = target_node;
}

void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*current_a;

	current_a = stack_a->head;
	find_maxmin(stack_b);
	while (current_a)
	{
		find_target_in_b(current_a, stack_b);
		current_a = current_a->next;
	}
}

void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*current_a;
	int				len_a;
	int				len_b;

	current_a = stack_a->head;
	len_a = stack_a->size;
	len_b = stack_b->size;
	while (current_a)
	{
		current_a->push_cost = current_a->index;
		if (!(current_a->above_median))
			current_a->push_cost = len_a - current_a->index;
		if (current_a->target_node->above_median)
			current_a->push_cost += current_a->target_node->index;
		else
			current_a->push_cost += len_b - current_a->target_node->index;
		current_a = current_a->next;
	}
}

void	ft_prep_moves_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_node(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
}
