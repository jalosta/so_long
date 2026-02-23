/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:48:06 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/23 14:44:04 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_file_or_exit(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == OPEN_FAIL)
	{
		print_err(strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static t_list	*read_map_lines(char *file)
{
	int		fd;
	char	*line;
	t_list	*lines;
	t_list	*node;

	fd = open_file_or_exit(file);
	lines = NULL;
	line = get_next_line_trimmed(fd);
	while (line != NULL)
	{
		node = ft_lstnew(line);
		if (node == NULL)
		{
			free(line);
			ft_lstclear(&lines, free);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&lines, node);
		line = get_next_line_trimmed(fd);
	}
	return (lines);
}

void	load_map(char *file, t_game *ctx)
{
	t_list	*lines;
	t_list	*node;
	size_t	i;

	lines = read_map_lines(file);
	ctx->map_size.y = ft_lstsize(lines);
	ctx->map = malloc((ctx->map_size.y + 1) * sizeof(char *));
	if (ctx->map == NULL)
	{
		ft_lstclear(&lines, free);
		exit(EXIT_FAILURE);
	}
	i = 0;
	node = lines;
	while (node != NULL)
	{
		ctx->map[i++] = node->content;
		node->content = NULL;
		node = node->next;
	}
	ctx->map[i] = NULL;
	ft_lstclear(&lines, free);
}
