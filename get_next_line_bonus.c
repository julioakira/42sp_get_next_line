/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:12 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/19 19:11:03 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*preserved_line[FD_SIZE];
	char		*line;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_SIZE)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (!preserved_line[fd])
		preserved_line[fd] = NULL;
	line = NULL;
	result = handler(fd, &buffer, &preserved_line[fd], &line);
	free(buffer);
	if (result <= 0 && !line)
	{
		line = NULL;
		preserved_line[fd] = NULL;
	}
	return (line);
}

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// all functions

int main(void)
{
	// int fd1 = open("./text_1.txt", O_RDWR);
	// int fd2 = open("./text_2.txt", O_RDWR);
	// int fd3 = open("./text_3.txt", O_RDWR);
	int fd_00 = open("../tests/empty", O_RDWR);
	int fd_01 = open("../tests/41_no_nl", O_RDWR);
	int fd_02 = open("../tests/42_no_nl", O_RDWR);
	int fd_03 = open("../tests/43_no_nl", O_RDWR);
	int fd_04 = open("../tests/41_with_nl", O_RDWR);
	int fd_05 = open("../tests/42_with_nl", O_RDWR);
	int fd_06 = open("../tests/43_with_nl", O_RDWR);
	int fd_07 = open("../tests/multiple_line_no_nl", O_RDWR);
	int fd_08 = open("../tests/multiple_line_no_with", O_RDWR);
	int fd_09 = open("../tests/multiple_nlx5", O_RDWR);
	int lines;

	lines = 0;
	while (lines++ < 10)
		printf("(%d) empty: %s\n", lines, get_next_line(fd_00));
	printf("\n");
	lines = 0;
	while (lines++ < 10)
		printf("(%d) 41_no_nl: %s\n", lines, get_next_line(fd_01));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) 42_no_nl: %s\n", lines, get_next_line(fd_02));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) 43_no_nl: %s\n", lines, get_next_line(fd_03));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) 41_with_nl: %s\n", lines, get_next_line(fd_04));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) 42_with_nl: %s\n", lines, get_next_line(fd_05));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) 43_with_nl: %s\n", lines, get_next_line(fd_06));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) multiple_line_no_nl: %s\n", lines, get_next_line(fd_07));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) multiple_line_with_nl: %s\n", lines, get_next_line(fd_08));
	lines = 0;
	while (lines++ < 10)
		printf("(%d) multiple_nlx5: %s\n", lines, get_next_line(fd_09));

	lines = 0;
	while (lines++ < 2)
		printf("(%d) empty: %s\n", lines, get_next_line(fd_00));
	printf("\n");
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 41_no_nl: %s\n", lines, get_next_line(fd_01));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 42_no_nl: %s\n", lines, get_next_line(fd_02));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) empty: %s\n", lines, get_next_line(fd_00));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 43_no_nl: %s\n", lines, get_next_line(fd_03));
	printf("\n");
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 41_no_nl: %s\n", lines, get_next_line(fd_01));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 41_with_nl: %s\n", lines, get_next_line(fd_04));
	printf("\n");
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 41_no_nl: %s\n", lines, get_next_line(fd_01));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) multiple_nlx5: %s\n", lines, get_next_line(fd_09));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) multiple_nlx5: %s\n", lines, get_next_line(fd_09));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 43_no_nl: %s\n", lines, get_next_line(fd_03));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 43_no_nl: %s\n", lines, get_next_line(fd_03));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 42_with_nl: %s\n", lines, get_next_line(fd_05));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 43_with_nl: %s\n", lines, get_next_line(fd_06));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) multiple_line_no_nl: %s\n", lines, get_next_line(fd_07));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) 42_with_nl: %s\n", lines, get_next_line(fd_05));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) multiple_line_with_nl: %s\n", lines, get_next_line(fd_08));
	lines = 0;
	while (lines++ < 2)
		printf("(%d) multiple_nlx5: %s\n", lines, get_next_line(fd_09));
}
