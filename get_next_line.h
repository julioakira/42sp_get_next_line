/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:15 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/26 04:15:26 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct node
{
	char			*content;
	int				counter;
	struct node	*next;
}				node_t;

node_t	*node_new(char *content);
void	node_add_back(node_t **node, node_t *new_node);
void	node_add_front(node_t **node, node_t *new_node);
int		get_nl_position(char *str);

char	*get_next_line(int fd);

#endif
