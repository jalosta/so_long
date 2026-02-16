/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:00:33 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/16 18:48:53 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int	x;
	int	y;

	x = begin.x;
	y = begin.y;
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return ;
	if (tab[y][x] == WALL || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	flood_fill(tab, size, (t_point){x + 1, y});
	flood_fill(tab, size, (t_point){x - 1, y});
	flood_fill(tab, size, (t_point){x, y + 1});
	flood_fill(tab, size, (t_point){x, y - 1});
}
