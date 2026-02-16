/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpoints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:49:56 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/16 17:28:54 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_is_rectangular(t_list *map, size_t ref_len)
{
	while (map != NULL)
	{
		if (ft_strlen(map->content) != ref_len)
			return (false);
		map = map->next;
	}
	return (true);
}

bool	map_is_enclosed(t_list *map, size_t width)
{
	char	*line;
	char	*end_line;

	line = map->content;
	while (*line != '\0')
	{
		if (*line != WALL)
			return (false);
		line++;
	}
	end_line = ft_lstlast(map)->content;
	if (EQUAL != ft_strncmp(line, end_line, width))
		return (false);
	map = map->next;
	while (map != NULL && map->content != end_line)
	{
		line = map->content;
		if (*line != WALL || line[width - 1] != WALL)
			return (false);
		map = map->next;
	}
	return (true);
}

bool	map_has_single_passage(t_list *map, char passage)
{
	char	*line;
	bool	found;

	found = false;
	while (map != NULL)
	{
		line = map->content;
		while (*line != '\0')
		{
			if (*line == passage)
			{
				if (found == true)
					return (false);
				found = true;
			}
			line++;
		}
		map = map->next;
	}
	return (found);
}

bool	map_has_collectible(t_list *map)
{
	while (map != NULL)
	{
		if (ft_strchr(map->content, COLLECTIBLE))
			return (true);
		map = map->next;
	}
	return (false);
}

bool	map_is_navigable(char **tab, size_t width, size_t map_height)
{
}
