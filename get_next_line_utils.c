/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:10 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/10 03:56:13 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_has_newline(char *str)
{
	size_t	idx;

	if (!str)
		return (0);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (1);
		idx++;
	}
	return (0);
}

// Unlike the original, needs to check str otherwise segfault.
size_t	ft_strlen(const char *str)
{
	size_t	idx;

	if (!str)
		return (0);
	idx = 0;
	while (str[idx])
	{
		idx++;
	}
	return (idx);
}

// Implementation without aux functions (memset and bzero)
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	idx;

	idx = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (idx < (nmemb * size))
	{
		((unsigned char *)ptr)[idx] = (unsigned char)0;
		idx++;
	}
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		*(p + --n) = (char)0;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	idx;
	size_t	s_idx;

	if (!s1 && !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	idx = 0;
	s_idx = 0;
	if (result == NULL)
		return (NULL);
	while (s1 && s1[idx])
	{
		result[idx] = s1[idx];
		idx++;
	}
	while (s2 && s2[s_idx])
	{
		result[idx] = s2[s_idx];
		idx++;
		s_idx++;
	}
	result[idx] = '\0';
	return (result);
}
