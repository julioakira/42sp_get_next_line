/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 04:00:28 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/02 04:01:20 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdio.h>
// Can be uncommented to remove "-D BUFFER_SIZE=X"
//#define BUFFER_SIZE 42

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd1 = open(argv[1], O_RDONLY);
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd1));
	}
}
