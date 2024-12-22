/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:30:52 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 14:44:58 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ft_end(ERROR_MEMORY);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->limits = (t_minmax *)malloc(sizeof(t_minmax));
	if (!stack->limits)
	{
		ft_free_stack(stack);
		ft_end(ERROR_MEMORY);
	}
	stack->limits->min = INT_MAX;
	stack->limits->max = INT_MIN;
	return (stack);
}

void	ft_push_to_stack(t_stack *stack, int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		ft_end(ERROR_MEMORY);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (stack->tail != NULL)
		stack->tail->next = new_node;
	else
		stack->head = new_node;
	stack->tail = new_node;
	stack->size++;
}
