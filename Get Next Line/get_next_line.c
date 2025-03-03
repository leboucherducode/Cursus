/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <jeschwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:09:55 by jeschwar          #+#    #+#             */
/*   Updated: 2024/12/05 10:05:14 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_finish(char **memory, int end_line)
{
	char	*line;
	char	*tmp;

	if (*memory[0] == '\0')
	{
		free(memory[0]);
		memory[0] = NULL;
		return (NULL);
	}
	if (end_line == 0)
	{
		line = memory[0];
		memory[0] = NULL;
		return (line);
	}
	tmp = ft_substr(memory[0], end_line, BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	line = ft_substr(memory[0], 0, end_line);
	free(memory[0]);
	memory[0] = tmp;
	return (line);
}

char	*file_read(char **memory, char *buffer, int fd)
{
	char	*end_line;
	int		count;
	char	*tmp;

	end_line = ft_strchr(memory[0], '\n');
	while (!end_line)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (free(memory[0]), memory[0] = NULL, NULL);
		if (count == 0)
			return (ft_finish(memory, 0));
		buffer[count] = '\0';
		tmp = ft_strjoin(memory[0], buffer);
		free (memory[0]);
		memory[0] = NULL;
		if (!tmp)
			return (NULL);
		memory[0] = tmp;
		end_line = ft_strchr(memory[0], '\n');
	}
	return (ft_finish(memory, end_line - memory[0] + 1));
}

char	*get_next_line(int fd)
{
	static char		*memory[1];
	char			*line;
	char			*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!memory[0])
		memory[0] = ft_strdup("");
	if (!memory[0])
		return (free(buffer), NULL);
	line = file_read(memory, buffer, fd);
	free (buffer);
	return (line);
}
