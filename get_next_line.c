/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:12 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/10 01:09:37 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

static char	*retrieve_line(char **buffer);
static char	*buffer_to_line(char **buffer, char *line);

static char	*buffer_to_line(char **buffer, char *line)
{
	size_t	idx;

	idx = 0;
	while ((*buffer)[idx])
	{
		line[idx] = (*buffer)[idx];
		if ((*buffer)[idx] == '\n')
		{
			line[idx] = (*buffer)[idx];
			idx++;
			break ;
		}
		idx++;
	}
	return (line);
}

static char	*retrieve_line(char **buffer)
{
	size_t	idx;
	char	*line;
	char	*ptr;

	idx = 0;
	if (!*buffer || *buffer[0] == '\0')
		return (NULL);
	while ((*buffer)[idx])
	{
		if ((*buffer)[idx] == '\n')
		{
			idx++;
			break ;
		}
		idx++;
	}
	line = ft_calloc((idx + 1), sizeof(char));
	if (!line)
		return (NULL);
	line = buffer_to_line(buffer, line);
	ptr = *buffer;
	*buffer = ft_strdup(&(*buffer)[idx]);
	free(ptr);
	return (line);
}

int	handler(int fd, char **buffer, char **preserved_line, char **line)
{
	char	*holder;
	int		read_checker;

	read_checker = 1;
	*line = NULL;
	while (!str_has_newline(*preserved_line) && read_checker)
	{
		read_checker = read(fd, *buffer, BUFFER_SIZE);
		if (read_checker < 0)
		{
			free(*buffer);
			return (-1);
		}
		holder = *preserved_line;
		// Leaking here
		*preserved_line = ft_strjoin(holder, *buffer);
		ft_bzero(*buffer, BUFFER_SIZE);
		if (holder)
			free(holder);
		if (read_checker == 0)
			break ;
	}
	if (*buffer)
	free(*buffer);
	if (read_checker == 0 && !*preserved_line[0])
	{
		return (-1);
	}
	*line = retrieve_line(preserved_line);
	return (read_checker);
}

// Needs to check buffer to see if file has ended
// if buffer = "" file has ended.
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*preserved_line;
	char		*line;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (!preserved_line)
		preserved_line = NULL;
	result = handler(fd, &buffer, &preserved_line, &line);
	if (result <= 0 && !line)
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
