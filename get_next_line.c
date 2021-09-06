/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:12 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/06 19:58:35 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

static char	*retrieve_line(char *buffer);
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
	while (!str_has_newline(preserved_line) && read_checker != 0)
	{
		read_checker = read(fd, buffer, BUFFER_SIZE);
		if (read_checker == -1)
		{
			free(buffer);
			return (NULL);
		}
		preserved_line = ft_strjoin(preserved_line, buffer);
		printf("Read checker: %lu\n", read_checker);
		printf("Buffer: %s\n", buffer);
		printf("Preserved line before: %s\n", preserved_line);
	}
	line = retrieve_line(preserved_line);
	free(buffer);
	return (line);
}

# include <fcntl.h>
# include <stdio.h>

int main(void)
{
	// 41_no_nl
	// multiple_line_with_nl
	int fd = open("../tests/41_no_nl", O_RDWR);
	char *str = get_next_line(fd);
	free(str);
}
