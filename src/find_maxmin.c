/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_maxmin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:43:27 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/27 20:16:56 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	find_maxmin(t_stack *stack)
{
	find_max(stack);
	find_min(stack);
}

void	find_max(t_stack *stack)
{
	t_stack_node	*current;

	if (!stack->head)
		ft_end(ERROR_EMPTY);
	stack->limits->max = stack->head->value;
	current = stack->head->next;
	while (current)
	{
		if (current->value > stack->limits->max)
			stack->limits->max = current->value;
		current = current->next;
	}
}

void	find_min(t_stack *stack)
{
	t_stack_node	*current;

	if (!stack->head)
		ft_end(ERROR_EMPTY);
	stack->limits->min = stack->head->value;
	current = stack->head->next;
	while (current)
	{
		if (current->value < stack->limits->min)
			stack->limits->min = current->value;
		current = current->next;
	}
}
