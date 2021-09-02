/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:12 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/02 03:40:55 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*retrieve_line(char *buffer);
static char	*retrieve_buffer(char *str);
static char	*buffer_to_line(char *buffer, char *line);

static char	*buffer_to_line(char *buffer, char *line)
{
	size_t	idx;

	idx = 0;
	while (buffer[idx])
	{
		line[idx] = buffer[idx];
		if (buffer[idx] == '\n')
		{
			line[idx] = buffer[idx];
			idx++;
			break ;
		}
		idx++;
	}
	return (line);
}

static char	*retrieve_line(char *buffer)
{
	size_t	idx;
	char	*line;

	idx = 0;
	if (!buffer)
		return (NULL);
	while (buffer[idx])
	{
		if (buffer[idx] == '\n')
		{
			idx++;
			break ;
		}
		idx++;
	}
	line = ft_calloc(idx + 1, sizeof(char));
	if (!line)
		return (NULL);
	line = buffer_to_line(buffer, line);
	return (line);
}

static char	*retrieve_buffer(char *buffer)
{
	size_t	idx;
	size_t	piece_idx;
	char	*buffer_piece;

	idx = 0;
	piece_idx = 0;
	if (!buffer)
		return (NULL);
	while (buffer[idx] && buffer[idx] != '\n')
		idx++;
	buffer_piece = ft_calloc((ft_strlen(buffer) - idx) + 1, sizeof(char));
	if (!buffer[idx] || !buffer_piece)
	{
		free(buffer);
		return (NULL);
	}
	idx++;
	while (buffer[idx])
	{
		buffer_piece[piece_idx] = buffer[idx];
		idx++;
		piece_idx++;
	}
	free(buffer);
	return (buffer_piece);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*preserved_line;
	ssize_t		read_checker;

	read_checker = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!str_is_line(preserved_line) && read_checker > 0)
	{
		read_checker = read(fd, buffer, BUFFER_SIZE);
		preserved_line = ft_strjoin(preserved_line, buffer);
	}
	free(buffer);
	if (read_checker == -1)
	{
		return (NULL);
	}
	line = retrieve_line(preserved_line);
	preserved_line = retrieve_buffer(preserved_line);
	if (read_checker == 0)
		return (preserved_line);
	return (line);
}
