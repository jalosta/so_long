/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:37:48 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/16 19:52:45 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_err(char *msg)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", msg);
}

static int	open_map_file(char *map_filename)
{
	int	map_fd;

	map_fd = open(map_filename, O_RDONLY);
	if (map_fd == OPEN_FAIL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

static void	print_err_list(char errors)
{
	if (errors & MAP_ERR_EMPTY)
		print_err("Map is empty");
	if (errors & MAP_ERR_NOT_RECTANGULAR)
		print_err("Map is not rectangular");
	if (errors & MAP_ERR_NOT_ENCLOSED)
		print_err("Map is not enclosed");
	if (errors & MAP_ERR_NO_SINGLE_EXIT)
		print_err("Map must have a single exit");
	if (errors & MAP_ERR_NO_SINGLE_START)
		print_err("Map must have a single starting position");
	if (errors & MAP_ERR_NO_COLLECTIBLE)
		print_err("Map must have at least one collectible");
	if (errors & MAP_ERR_NO_VALID_PATH)
		print_err("Exit, starting position and collectibles must be reachable");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	char	err_check;

	if (ac != 2)
	{
		print_err(strerror(EINVAL));
		ft_dprintf(STDERR_FILENO, "Usage: ./so_long <map>\n");
		exit(EXIT_FAILURE);
	}
	err_check = evaluate_map(open_map_file(av[1]));
	if (err_check)
		print_err_list(err_check);
}
