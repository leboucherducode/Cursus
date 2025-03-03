/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <jeschwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:09:55 by jeschwar          #+#    #+#             */
/*   Updated: 2024/12/05 10:05:06 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_finish(char **memory, int end_line, int fd)
{
	char	*line;
	char	*tmp;

	if (*memory[fd] == '\0')
	{
		free(memory[fd]);
		memory[fd] = NULL;
		return (NULL);
	}
	if (end_line == 0)
	{
		line = memory[fd];
		memory[fd] = NULL;
		return (line);
	}
	tmp = ft_substr(memory[fd], end_line, BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	line = ft_substr(memory[fd], 0, end_line);
	free(memory[fd]);
	memory[fd] = tmp;
	return (line);
}

char	*file_read(char **memory, char *buffer, int fd)
{
	char	*end_line;
	int		count;
	char	*tmp;

	end_line = ft_strchr(memory[fd], '\n');
	while (!end_line)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (free(memory[fd]), memory[fd] = NULL, NULL);
		if (count == 0)
			return (ft_finish(memory, 0, fd));
		buffer[count] = '\0';
		tmp = ft_strjoin(memory[fd], buffer);
		free (memory[fd]);
		memory[fd] = NULL;
		if (!tmp)
			return (NULL);
		memory[fd] = tmp;
		end_line = ft_strchr(memory[fd], '\n');
	}
	return (ft_finish(memory, end_line - memory[fd] + 1, fd));
}

char	*get_next_line(int fd)
{
	static char		*memory[FD_MAX + 1];
	char			*line;
	char			*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FD_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!memory[fd])
		memory[fd] = ft_strdup("");
	if (!memory[fd])
		return (free(buffer), NULL);
	line = file_read(memory, buffer, fd);
	free (buffer);
	return (line);
}
