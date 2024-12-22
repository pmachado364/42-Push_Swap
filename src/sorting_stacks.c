/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:52:17 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 16:45:09 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

void	ft_sorting_stacks(t_stack *stack_a, t_stack *stack_b,
							t_cmd_list *cmd)
{
	if (sorted_or_not(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		ft_free_command_list(cmd);
		exit(1);
	}
	if (stack_a->size == 2)
		ft_sort_two(stack_a, cmd);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a, cmd);
	else if (stack_a->size == 4)
		ft_sort_four(stack_a, stack_b, cmd);
	else
		ft_sort_big(stack_a, stack_b, cmd);
}
