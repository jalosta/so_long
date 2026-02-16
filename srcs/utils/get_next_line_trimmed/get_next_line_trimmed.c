/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_trimmed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:02:59 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/16 18:16:50 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_trimmed.h"

static void	free_if_heaped(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*keep_leftover(char **str, size_t start, size_t len)
{
	char	*stash;

	stash = ft_substr(*str, start, len);
	if (stash == NULL)
		return (NULL);
	free_if_heaped((void **)str);
	return (stash);
}

static char	*pull_line_from_stash(char **str)
{
	char	*newline;
	size_t	len;
	char	*line;

	newline = ft_strchr(*str, '\n');
	if (newline == NULL)
	{
		line = ft_strdup(*str);
		return (free_if_heaped((void **)str), line);
	}
	len = (size_t)(newline - *str);
	if (len == 0)
		line = ft_strdup(EMPTY_STRING);
	else
		line = ft_substr(*str, 0, len);
	if (line == NULL)
		return (free_if_heaped((void **)str), NULL);
	*str = keep_leftover(str, len + 1, ft_strlen(newline + 1));
	if (*str == NULL)
		return (free_if_heaped((void **)&line), NULL);
	return (line);
}

static char	*read_and_append(char *str, int fd)
{
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE + 1];

	if (str != NULL && ft_strchr(str, '\n'))
		return (str);
	while (INFINITE_LOOP)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == READ_ERROR)
			return (free_if_heaped((void **)&str), NULL);
		if (bytes == END_OF_FILE)
			return (str);
		buffer[bytes] = '\0';
		if (str == NULL)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(str, buffer);
		if (str == NULL)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			return (str);
	}
}

char	*get_next_line_trimmed(int fd)
{
	static char	*s_str;
	char		*line;

	s_str = read_and_append(s_str, fd);
	if (s_str == NULL)
		return (NULL);
	if (*s_str == '\0')
		return (free_if_heaped((void **)&s_str), NULL);
	line = pull_line_from_stash(&s_str);
	return (line);
}
