/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpoints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:49:56 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/17 16:56:07 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_rectangular(t_list *map, size_t ref_len)
{
	while (map != NULL)
	{
		if (ft_strlen(map->content) != ref_len)
			return (false);
		map = map->next;
	}
	return (true);
}

bool	is_enclosed(t_list *map, size_t width)
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
	if (EQUAL != ft_strncmp(map->content, end_line, width))
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

bool	has_passage(t_list *map, char passage)
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

bool	has_collectible(t_list *map)
{
	while (map != NULL)
	{
		if (ft_strchr(map->content, COLLECTIBLE))
			return (true);
		map = map->next;
	}
	return (false);
}

bool	is_navigable(char **tab)
{
	t_point	start;
	t_point	size;
	int		y;
	int		x;

	y = -1;
	while (tab[++y] != NULL)
	{
		x = -1;
		while (tab[y][++x] != '\0')
			if (tab[y][x] == START)
				start = (t_point){x, y};
	}
	size = (t_point){ft_strlen(tab[0]), y};
	flood_fill(tab, size, start);
	y = -1;
	while (tab[++y] != NULL)
	{
		x = -1;
		while (tab[y][++x] != '\0')
			if (tab[y][x] == EXIT || tab[y][x] == START
				|| tab[y][x] == COLLECTIBLE)
				return (false);
	}
	return (true);
}
