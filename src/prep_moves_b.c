/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_moves_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:03:07 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/27 20:17:11 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	find_target_in_a(t_stack_node *current_b, t_stack *stack_a)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_value;

	current_a = stack_a->head;
	target_node = NULL;
	best_match_value = LONG_MAX;
	while (current_a)
	{
		if (current_a->value > current_b->value
			&& current_a->value < best_match_value)
		{
			best_match_value = current_a->value;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (!target_node)
		current_b->target_node = find_minimum(stack_a);
	else
		current_b->target_node = target_node;
}

void	set_target_b(t_stack *stack_b, t_stack *stack_a)
{
	t_stack_node	*current_b;

	if (!stack_b->head || !stack_a->head)
		return ;
	current_b = stack_b->head;
	find_maxmin(stack_a);
	while (current_b)
	{
		find_target_in_a(current_b, stack_a);
		current_b = current_b->next;
	}
}

void	ft_prep_moves_b(t_stack *stack_b, t_stack *stack_a)
{
	if (!stack_b->head)
		return ;
	current_index(stack_b);
	current_index(stack_a);
	set_target_b(stack_b, stack_a);
}
