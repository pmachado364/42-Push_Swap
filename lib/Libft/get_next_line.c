/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:02:31 by pmachado          #+#    #+#             */
/*   Updated: 2024/06/19 11:02:31 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*store_data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	store_data = ft_read_function(fd, store_data);
	if (!store_data)
		return (NULL);
	line = ft_extractline(store_data);
	store_data = ft_update_remainder(store_data);
	return (line);
}

char	*ft_read_function(int fd, char *str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free_data(str, buffer));
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_extractline(char *store_data)
{
	int		i;
	char	*line;

	i = 0;
	if (!store_data[i])
		return (NULL);
	while (store_data[i] && store_data[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (store_data[i] && store_data[i] != '\n')
	{
		line[i] = store_data[i];
		i++;
	}
	if (store_data[i] == '\n')
	{
		line[i] = store_data[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_remainder(char *store_data)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	j = 0;
	while (store_data[i] && store_data[i] != '\n')
		i++;
	if (!store_data[i])
	{
		free(store_data);
		return (NULL);
	}
	remainder = malloc((ft_strlen(store_data) - i + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	i++;
	while (store_data[i])
		remainder[j++] = store_data[i++];
	remainder[j] = '\0';
	free(store_data);
	return (remainder);
}
