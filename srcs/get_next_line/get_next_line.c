/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:02:59 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/10 11:16:08 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_if_heaped(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*append_char(char *line, char *c)
{
	char	*joined;

	joined = ft_strjoin(line, c);
	free_if_heaped((void **)&line);
	return (joined);
}

static char	*read_line(int fd)
{
	ssize_t	e_check;
	char	c;
	char	*line;

	line = ft_strdup(EMPTY_STRING);
	if (line == NULL)
		return (NULL);
	e_check = read(fd, &c, 1);
	while (c != '\n')
	{
		if (e_check == READ_ERROR)
			return (free_if_heaped((void **)&line), NULL);
		if (e_check == END_OF_FILE)
		{
			if (*line == '\0')
				return (free_if_heaped((void **)&line), NULL);
			return (line);
		}
		line = append_char(line, &c);
		if (line == NULL)
			return (NULL);
		e_check = read(fd, &c, 1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	return (read_line(fd));
}
