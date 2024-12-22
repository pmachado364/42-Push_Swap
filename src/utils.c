/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:19:22 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 14:47:56 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

int	ft_contains_space(const char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (stack->limits)
	{
		free(stack->limits);
		stack->limits = NULL;
	}
	free(stack);
	stack = NULL;
}

bool	sorted_or_not(t_stack *stack)
{
	t_stack_node	*current_node;
	size_t			i;

	i = 1;
	current_node = stack->head;
	while (i < stack->size)
	{
		if (current_node->value > current_node->next->value)
			return (false);
		current_node = current_node->next;
		i++;
	}
	return (true);
}

bool	reverse_sorted_or_not(t_stack *stack)
{
	t_stack_node	*current_node;
	size_t			i;

	i = 1;
	current_node = stack->head;
	while (i < stack->size)
	{
		if (current_node->value < current_node->next->value)
			return (false);
		current_node = current_node->next;
		i++;
	}
	return (true);
}

t_stack_node	*find_min_node(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*min_node;

	current = stack->head;
	min_node = current;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}
