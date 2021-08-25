/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:34:45 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/25 01:26:11 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *read_test(int fd)
{
	char *buffer;

	buffer = malloc(BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

// gcc -Wextra -Wall -Werror -D BUFFER_SIZE=42 read_test.c && ./a.out ./41_no_nl
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
			// printf("Atgv: %s\n", argv[1]);
			printf("Testing: \n");
			printf("%s", read_test(fd));
		return (0);
	}
}
