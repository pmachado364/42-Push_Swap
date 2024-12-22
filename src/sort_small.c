/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:24:55 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/30 14:18:54 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	ft_sort_two(t_stack *stack, t_cmd_list *cmd)
{
	sx(stack, "sa", cmd);
	printf("Performed swap\n");
}

void	ft_sort_three(t_stack *stack, t_cmd_list *cmd)
{
	t_stack_node	*biggest_node;

	biggest_node = find_maximum(stack);
	if (biggest_node == stack->head)
		rx(stack, "ra", cmd);
	else if (biggest_node == stack->head->next)
		rrx(stack, "rra", cmd);
	if (stack->head->value > stack->head->next->value)
		sx(stack, "sa", cmd);
}

void	ft_sort_four(t_stack *stack_a, t_stack *stack_b,
						t_cmd_list *cmd)
{
	px(stack_a, stack_b, "pb", cmd);
	if (!sorted_or_not(stack_a))
		ft_sort_three(stack_a, cmd);
	ft_prep_moves_b(stack_b, stack_a);
	ft_move_b_to_a(stack_b, stack_a, cmd);
	if (!sorted_or_not(stack_a))
	{
		current_index(stack_a);
		ft_min_on_top(stack_a, cmd);
	}
}
