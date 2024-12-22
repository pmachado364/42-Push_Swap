/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:01:31 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 14:04:06 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	ft_swap(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !stack->head || stack->size < 2)
		ft_end(ERROR_C_STACK);
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL )
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void	sx(t_stack *stack, const char *name, t_cmd_list *cmd)
{
	if (stack && stack->size >= 2)
		ft_swap(stack);
	if (name && cmd)
		ft_add_command(cmd, name);
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_cmd_list *cmd)
{
	sx(stack_a, NULL, NULL);
	sx(stack_b, NULL, NULL);
	ft_add_command(cmd, "ss");
}
