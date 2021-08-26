/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:47:09 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/26 04:19:24 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*lkd_read_all(int fd)
{
	node_t	*new_node;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	new_node = node_new(buffer);
	read(fd, new_node->content, BUFFER_SIZE);
	return (new_node->content);
}

char	*lkd_read_line(int fd)
{
	node_t	*new_node;
	char	*buffer;
	size_t	nl_position;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	nl_position = get_nl_position(buffer);
	new_node = node_new(buffer);
	if (buffer && nl_position == 0)
		new_node->content = buffer;
	else if(buffer && nl_position > 0)
		new_node->content = strtok(buffer, "\n");
	return (new_node->content);
}

// gcc -Wextra -Wall -Werror -D BUFFER_SIZE=42 read_test.c && ./a.out ./41_no_nl
// gcc -Wextra -Wall -Werror -D BUFFER_SIZE=500 read_test.c && ./a.out ./multiple_line_with_nl
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
			// printf("Atgv: %s\n", argv[1]);
			printf("Testing read_line: \n");
			printf("%s", lkd_read_line(fd));
			printf("\n--------------------\n");
			printf("Testing read_all: \n");
			printf("%s", lkd_read_all(fd));
		return (0);
	}
}
