/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:51:58 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/25 00:14:36 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
// Works like this a regular define but in compile time.
// #define BUFFER_SIZE 42

// Compiling with gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42
// -D BUFFER_SIZE=X on command line only accepts int?
int main(void)
{
	printf("BUFFER SIZE: %d\n", BUFFER_SIZE);
}
