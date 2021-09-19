/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:10 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/19 17:50:15 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	str_has_newline(char *str)
{
	size_t	idx;

	if (!str || !str[0])
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

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
		*(p + --n) = (char)0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*ptr;
	size_t	s_len;

	s_len = 0;
	while (s && s[s_len])
		s_len++;
	dup = malloc(s_len + 1);
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*secondary;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	while (s2 && s2[s2_len])
		s2_len++;
	result = ft_calloc(s1_len + s2_len + 1, 1);
	if (result)
	{
		secondary = result;
		while (s1 && *s1)
			*secondary++ = *s1++;
		while (s2 && *s2)
			*secondary++ = *s2++;
		*secondary = 0;
		return (result);
	}
	return (NULL);
}
