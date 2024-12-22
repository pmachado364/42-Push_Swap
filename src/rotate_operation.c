/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:13:16 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 14:03:59 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	ft_rotate_x(t_stack *stack)
{
	t_stack_node	*old_head;
	t_stack_node	*new_head;

	if (!stack || !stack->head || stack->size < 2)
		ft_end(ERROR_C_STACK);
	new_head = stack->head->next;
	old_head = stack->head;
	stack->head = new_head;
	stack->head->prev = NULL;
	old_head->next = NULL;
	old_head->prev = stack->tail;
	stack->tail->next = old_head;
	stack->tail = old_head;
}

void	rx(t_stack *stack, const char *name, t_cmd_list *cmd)
{
	if (stack && stack->size >= 2)
	{
		ft_rotate_x(stack);
		if (name && cmd)
			ft_add_command(cmd, name);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *cmd)
{
	rx(stack_a, NULL, NULL);
	rx(stack_b, NULL, NULL);
	if (cmd)
		ft_add_command(cmd, "rr");
}
