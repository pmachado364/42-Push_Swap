/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:24:59 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/01 16:43:44 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"
#include "libft.h"

static bool	ft_parse_string(t_stack *stack, char *str);
static bool	ft_parse_array(t_stack *stack, int argc, char **argv);

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack;
	bool	numbers_parsed;

	numbers_parsed = false;
	if (argc < 2)
		exit(1);
	stack = ft_create_stack();
	if (argc == 2 && (ft_is_single_number(argv[1])))
	{
		ft_free_stack(stack);
		exit(1);
	}
	if (argc == 2 && ft_contains_space(argv[1]))
		numbers_parsed = ft_parse_string(stack, argv[1]);
	else
		numbers_parsed = ft_parse_array(stack, argc, argv);
	if (!numbers_parsed || stack->size == 0)
	{
		ft_free_stack(stack);
		ft_end(ERROR_C_STACK);
	}
	return (stack);
}

static bool	ft_parse_string(t_stack *stack, char *str)
{
	char	**values;
	size_t	i;
	int		value;
	bool	parsed_numbers;

	parsed_numbers = false;
	values = ft_split(str, ' ');
	if (!values || ft_check_input_errors(values))
	{
		ft_free_split(&values);
		ft_free_stack(stack);
		ft_end(ERROR_INPUT);
	}
	i = 0;
	while (values[i])
	{
		value = ft_atoi(values[i]);
		ft_push_to_stack(stack, value);
		parsed_numbers = true;
		i++;
	}
	ft_free_split(&values);
	return (parsed_numbers);
}

static bool	ft_parse_array(t_stack *stack, int argc, char **argv)
{
	int		value;
	bool	parsed_numbers;

	parsed_numbers = false;
	while (++argv, --argc)
	{
		if (ft_isint(*argv))
		{
			value = ft_atoi(*argv);
			ft_push_to_stack(stack, value);
			parsed_numbers = true;
		}
		else
		{
			ft_free_stack(stack);
			ft_end(ERROR_ARGS);
		}
	}
	if (stack->size < 2)
	{
		ft_free_stack(stack);
		ft_end(ERROR_INPUT);
	}
	return (parsed_numbers);
}
