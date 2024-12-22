/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:13:55 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 14:04:10 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	ft_rev_rotate_x(t_stack *stack)
{
	t_stack_node	*old_tail;

	if (!stack || !stack->head || stack->size < 2)
		ft_end(ERROR_C_STACK);
	old_tail = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	stack->head->prev = old_tail;
	old_tail->next = stack->head;
	old_tail->prev = NULL;
	stack->head = old_tail;
}

void	rrx(t_stack *stack, const char *name, t_cmd_list *cmd)
{
	if (stack && stack->size >= 2)
	{
		ft_rev_rotate_x(stack);
		if (name && cmd)
			ft_add_command(cmd, name);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *cmd)
{
	rrx(stack_a, NULL, NULL);
	rrx(stack_b, NULL, NULL);
	if (cmd)
		ft_add_command(cmd, "rrr");
}
