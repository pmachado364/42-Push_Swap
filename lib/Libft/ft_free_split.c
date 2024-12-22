/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:27 by pmachado          #+#    #+#             */
/*   Updated: 2024/09/03 16:02:19 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char ***split)
{
	char	**current;

	if (split && *split)
	{
		current = ((*split));
		while ((*current))
			free((*(current++)));
		free((*split));
		(*split) = NULL;
	}
}
