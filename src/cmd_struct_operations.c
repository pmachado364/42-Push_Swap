/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:56:57 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/27 20:16:44 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

t_cmd_list	*init_command_list(void)
{
	t_cmd_list	*list;

	list = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	if (!list)
		ft_end(ERROR_MEMORY);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	ft_add_command(t_cmd_list *list, const char *cmd)
{
	t_cmd	*new_move;

	new_move = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_move)
		ft_end(ERROR_MEMORY);
	new_move->instruction = ft_strdup(cmd);
	new_move->next = NULL;
	if (!list->head)
	{
		list->head = new_move;
		list->tail = new_move;
	}
	else
	{
		list->tail->next = new_move;
		list->tail = new_move;
	}
	list->size++;
}

void	ft_print_commands(t_cmd_list *list)
{
	t_cmd	*current;

	current = list->head;
	while (current)
	{
		ft_printf("%s\n", current->instruction);
		current = current->next;
	}
}

void	ft_free_command_list(t_cmd_list *list)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		next = current->next;
		free(current->instruction);
		free(current);
		current = next;
	}
	free(list);
}
