/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:10 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/26 04:20:14 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

node_t	*node_new(char *content)
{
	node_t	*new_node;

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->counter = 0;
	return (new_node);
}

void	node_add_back(node_t **node, node_t *new_node)
{
	node_t	*last_node;

	if (!new_node)
		return ;
	last_node = *node;
	if (!*node)
		*node = new_node;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

void	node_add_front(node_t **node, node_t *new_node)
{
	if (!new_node || !node)
		return ;
	new_node->next = *node;
	*node = new_node;
}

int	get_nl_position(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (-1);
	while (str[idx])
	{
		if (str[idx] == '\n')
			break ;
		idx++;
	}
	return (idx);
}
