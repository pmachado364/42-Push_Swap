/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:49:45 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 15:00:17 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

bool	ft_check_input_errors(char **values)
{
	size_t	i;

	if (values[0] == NULL)
		return (true);
	i = 0;
	while (values[i])
	{
		if (!ft_isint(values[i]))
			return (true);
		i++;
	}
	if (i < 2)
		return (true);
	return (false);
}

bool	ft_is_single_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	ft_free_split(char ***values)
{
	size_t	i;

	i = 0;
	if (values && *values)
	{
		while ((*values)[i])
		{
			free((*values)[i]);
			i++;
		}
		free(*values);
		*values = NULL;
	}
}

void	ft_check_duplicates(t_stack *stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->value == temp->value)
			{
				ft_free_stack(stack);
				ft_end(ERROR_DUPLICATE);
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

void	ft_end(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
