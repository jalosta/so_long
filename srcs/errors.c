/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:49:56 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/13 15:37:06 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_is_rectangular(t_list *map)
{
	size_t	ref_len;

	ref_len = ft_strlen(map->content);
	while (map)
	{
		if (ft_strlen(map->content) != ref_len)
			return (false);
		map = map->next;
	}
	return (true);
}

bool	map_is_enclosed(t_list *map)
{
	size_t	ref_len;
}

bool	map_has_single_exit(t_list *map)
{
	(void)map;
	return (true);
}

bool	map_has_single_start(t_list *map)
{
	(void)map;
	return (true);
}

bool	map_has_collectible(t_list *map)
{
	(void)map;
	return (true);
}
