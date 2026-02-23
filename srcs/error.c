/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:45:56 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/23 16:22:37 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", msg);
}

void	print_err_list(char errors)
{
	if (errors & MAP_ERR_UNEVEN_LEN)
		print_err("Map is not rectangular");
	if (errors & MAP_ERR_AGAPE)
		print_err("Map is not enclosed with walls");
	if (errors & MAP_ERR_NO_VALID_EXIT)
		print_err("Map must have a single exit");
	if (errors & MAP_ERR_NO_VALID_START)
		print_err("Map must have a single starting position");
	if (errors & MAP_ERR_NO_COLLECTIBLE)
		print_err("Map must have at least one collectible");
	if (errors & MAP_ERR_NO_VALID_PATH)
		print_err("Exit, starting position and collectibles must be reachable");
	exit(EXIT_FAILURE);
}
