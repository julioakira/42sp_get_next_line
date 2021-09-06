#include <stdlib.h>
#include <stdio.h>

int	str_is_line(char *str)
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

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup = malloc(s_len + 1);
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_piece_len;
	char	*substr;
	size_t	idx;
	size_t	smaller;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	idx = 0;
	s_piece_len = ft_strlen(&s[start]);
	if (len < s_piece_len)
		smaller = len;
	else
		smaller = s_piece_len;
	printf("smaller: %lu\n", smaller + 1);
	substr = malloc(smaller + 1 * sizeof (char));
	if (!substr)
		return (NULL);
	while (idx < len && s[start + idx])
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	idx;
	size_t	s_idx;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	idx = 0;
	s_idx = 0;
	if (!result)
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

static char	*split_line(char **result)
{
	char	*result_cpy;
	char	*result_holder;
	size_t	idx;

	idx = 0;
	while ((*result)[idx])
	{
		if ((*result)[idx] == '\n')
		{
			idx++;
			break ;
		}
		idx++;
	}
	if (idx == 0 || !*result)
		return (NULL);
	result_holder = *result;
	result_cpy = ft_substr(result_holder, 0, idx);
	*result = ft_strdup(&(*result)[idx]);
	free(result_holder);
	return (result_cpy);
}

int main(void)
{
	char *str = ft_strdup("Hello\nworld");
	printf("split: %s", split_line(&str));
	printf("str after: %s", str);
	free(str);
	return (0);
}
