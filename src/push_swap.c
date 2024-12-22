/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:06:46 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/30 17:50:14 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_cmd_list	*cmd;

	stack_a = ft_parse(argc, argv);
	ft_check_duplicates(stack_a);
	stack_b = ft_create_stack();
	cmd = init_command_list();
	ft_sorting_stacks(stack_a, stack_b, cmd);
	ft_print_commands(cmd);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	ft_free_command_list(cmd);
	return (0);
}
