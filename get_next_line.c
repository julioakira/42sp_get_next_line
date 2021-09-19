/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:12 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/19 18:09:36 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*retrieve_line(char **buffer);
static char	*buffer_to_line(char **buffer, char *line);
static int	handler(int fd, char **buffer, char **preserved_line, char **line);
static void	free_and_reset(void *ptr);

static void	free_and_reset(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

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

static int	handler(int fd, char **buffer, char **preserved_line, char **line)
{
	char	*holder;
	int		read_checker;

	read_checker = 1;
	while (!str_has_newline(*preserved_line) && read_checker)
	{
		read_checker = read(fd, *buffer, BUFFER_SIZE);
		if (read_checker < 0)
			return (-1);
		holder = *preserved_line;
		*preserved_line = ft_strjoin(holder, *buffer);
		ft_bzero(*buffer, BUFFER_SIZE);
		free_and_reset(holder);
		if (read_checker == 0)
			break ;
	}
	if (read_checker == 0 && !(*preserved_line)[0])
	{
		free_and_reset(*preserved_line);
		return (-1);
	}
	*line = retrieve_line(preserved_line);
	return (read_checker);
}

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
	line = NULL;
	result = handler(fd, &buffer, &preserved_line, &line);
	free(buffer);
	if (result <= 0 && !line)
		preserved_line = NULL;
	return (line);
}
