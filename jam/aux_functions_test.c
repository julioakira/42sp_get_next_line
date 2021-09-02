/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 06:17:04 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/31 06:21:20 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s && s[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	idx;
	size_t	s_idx;

	if (!s1 && !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	idx = 0;
	s_idx = 0;
	if (result == NULL)
		return (NULL);
	while (s1[idx])
	{
		result[idx] = s1[idx];
		idx++;
	}
	while (s2[s_idx])
	{
		result[idx] = s2[s_idx];
		idx++;
		s_idx++;
	}
	result[idx] = '\0';
	return (result);
}

int main()
{
    char *s1 = "Lalala";
    char *s2 = NULL;
    printf("Joined: %s\n", ft_strjoin(s2, s1));
}
