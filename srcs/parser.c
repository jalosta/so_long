/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:34:32 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/13 15:27:26 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*trace_map(int map_fd)
{
	t_list	*head;
	t_list	*node;
	char	*line;

	head = NULL;
	line = get_next_line_trimmed(map_fd);
	while (line != NULL)
	{
		node = ft_lstnew(line);
		if (node == NULL)
		{
			free(line);
			ft_lstclear(&head, free);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&head, node);
		line = get_next_line_trimmed(map_fd);
	}
	return (head);
}

char	evaluate_map(int map_fd)
{
	char	errors;
	t_list	*map;

	errors = 0;
	map = trace_map(map_fd);
	if (map == NULL)
		return (MAP_ERR_EMPTY);
	if (false == map_is_rectangular(map))
		errors |= MAP_ERR_NOT_RECTANGULAR;
	if (false == map_is_enclosed(map))
		errors |= MAP_ERR_NOT_ENCLOSED;
	if (false == map_has_single_exit(map))
		errors |= MAP_ERR_NO_EXIT;
	if (false == map_has_single_start(map))
		errors |= MAP_ERR_NO_START;
	if (false == map_has_collectible(map))
		errors |= MAP_ERR_NO_COLLECTIBLE;
	ft_lstclear(&map, free);
	return (errors);
}
