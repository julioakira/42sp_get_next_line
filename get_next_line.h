/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:58:15 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/10 01:31:01 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <string.h>

// Auxiliary functions
int		str_has_newline(char *str);
size_t	ft_strlen(const char *str);
void    *ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);

// Main function
char	*get_next_line(int fd);
#endif
