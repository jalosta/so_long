/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:34:32 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/16 17:36:44 by jalosta-         ###   ########.fr       */
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

static char	**build_table(t_list *map)
{
	char	**tab;
	size_t	i;

	i = 0;
	while (map != NULL)
	{
		tab[i] = ft_strdup(map->content);
		map = map->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	evaluate_map(int map_fd, char error_mask)
{
	t_list	*map;
	size_t	width;
	size_t	height;

	map = trace_map(map_fd);
	if (map == NULL)
		return (MAP_ERR_EMPTY);
	width = ft_strlen(map->content);
	height = ft_lstsize(map);
	error_mask = 0;
	if (false == map_is_rectangular(map, width))
		error_mask |= MAP_ERR_NOT_RECTANGULAR;
	if (false == map_is_enclosed(map, width))
		error_mask |= MAP_ERR_NOT_ENCLOSED;
	if (false == map_has_single_passage(map, EXIT))
		error_mask |= MAP_ERR_NO_SINGLE_EXIT;
	if (false == map_has_single_passage(map, START))
		error_mask |= MAP_ERR_NO_SINGLE_START;
	if (false == map_has_collectible(map))
		error_mask |= MAP_ERR_NO_COLLECTIBLE;
	if (false == map_is_navigable(build_table(map), width, height))
		error_mask |= MAP_ERR_NO_VALID_PATH;
	ft_lstclear(&map, free);
}
