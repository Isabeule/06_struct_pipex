/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:46:57 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/20 12:47:35 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../includes/pipex_bonus.h"

char	*ft_set_line(char *line_buffer)
{
	char	*left_chars;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[1] == '\0')
		return (NULL);
	left_chars = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_chars == '\0')
	{
		free(left_chars);
		left_chars = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (left_chars);
}

char	*ft_fill_line_buffer(int fd, char *left_chars, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
	while (b_read)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_chars);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!left_chars)
			left_chars = ft_strdup("");
		temp = left_chars;
		left_chars = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_chars);
}

char	*get_next_line(int fd)
{
	static char	*left_chars;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_fill_line_buffer(fd, left_chars, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_chars = ft_set_line(line);
	return (line);
}
