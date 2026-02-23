/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpoints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:26:05 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/23 16:59:32 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	validate_row_lengths(char **map, t_game *ctx)
{
	size_t	ref_len;

	ref_len = ft_strlen(map[0]);
	while (*map)
	{
		if (ft_strlen(*map) != ref_len)
			return (MAP_ERR_UNEVEN_LEN);
		map++;
	}
	ctx->map_size.x = (int)ref_len;
	return (EXIT_SUCCESS);
}

char	validate_walls(char **map, t_game *ctx)
{
	char	*top;
	char	*bottom;
	int		width;

	width = ctx->map_size.x;
	top = map[0];
	bottom = map[ctx->map_size.y - 1];
	while (*top)
		if (*top++ != WALL)
			return (MAP_ERR_AGAPE);
	while (*bottom)
		if (*bottom++ != WALL)
			return (MAP_ERR_AGAPE);
	map++;
	while (*map && *map != bottom)
	{
		if ((*map)[0] != WALL || (*map)[width - 1] != WALL)
			return (MAP_ERR_AGAPE);
		map++;
	}
	return (EXIT_SUCCESS);
}

char	validate_unique_passage(char **map, char passage)
{
	bool	found;
	char	*row;
	char	err;

	if (passage == START)
		err = MAP_ERR_NO_VALID_START;
	else
		err = MAP_ERR_NO_VALID_EXIT;
	found = false;
	while (*map)
	{
		row = *map++;
		while (*row)
		{
			if (*row++ == passage)
			{
				if (found == true)
					return (err);
				found = true;
			}
		}
	}
	if (found == false)
		return (err);
	return (EXIT_SUCCESS);
}

char	count_collectibles(char **map, t_game *ctx)
{
	int		count;
	char	*row;

	count = 0;
	while (*map != NULL)
	{
		row = *map;
		while (*row != '\0')
		{
			if (*row == COLLECTIBLE)
				count++;
			row++;
		}
		map++;
	}
	ctx->collectibles = count;
	if (count == 0)
		return (MAP_ERR_NO_COLLECTIBLE);
	return (EXIT_SUCCESS);
}

bool	is_navigable(char **tab, t_point size)
{
	t_point	cur;
	bool	found;

	found = false;
	cur.y = -1;
	while (found == false && tab[++cur.y])
	{
		cur.x = -1;
		while (found == false && tab[cur.y][++cur.x])
			if (tab[cur.y][cur.x] == START)
				found = true;
	}
	flood_fill(tab, size, cur);
	cur.y = -1;
	while (tab[++cur.y])
	{
		cur.x = -1;
		while (tab[cur.y][++cur.x])
			if (tab[cur.y][cur.x] == EXIT || tab[cur.y][cur.x] == COLLECTIBLE)
				return (false);
	}
	return (true);
}
