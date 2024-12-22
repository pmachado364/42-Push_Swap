/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:05:04 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/27 20:17:15 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

t_stack_node	*ft_pop(t_stack *stack)
{
	t_stack_node	*elem;

	if (!stack || !stack->head || stack->size == 0)
		ft_end(ERROR_C_STACK);
	elem = stack->head;
	stack->head = stack->head->next;
	if (stack->head != NULL)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	stack->size--;
	return (elem);
}

void	ft_push(t_stack *stack, t_stack_node *elem)
{
	if (!stack || !elem)
		return ;
	elem->next = stack->head;
	elem->prev = NULL;
	if (stack->head != NULL)
		stack->head->prev = elem;
	else
		stack->tail = elem;
	stack->head = elem;
	stack->size++;
}

void	px(t_stack *from_stack, t_stack *to_stack,
			const char *name, t_cmd_list *cmd)
{
	t_stack_node	*elem;

	elem = ft_pop(from_stack);
	if (elem != NULL)
	{
		ft_push(to_stack, elem);
		if (name && cmd)
			ft_add_command(cmd, name);
	}
}
