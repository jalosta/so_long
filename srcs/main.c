/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:37:48 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/11 17:01:15 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		map_fd;
	char	*line;

	if (ac != 2)
	{
		ft_dprintf(STDERR_FILENO, "Error: %s\n", strerror(EINVAL));
		ft_dprintf(STDERR_FILENO, "Usage: ./so_long <map>\n");
		return (EXIT_FAILURE);
	}
	map_fd = open(av[1], O_RDONLY);
	if (map_fd == OPEN_FAIL)
		return (perror("Error"), close(map_fd), EXIT_FAILURE);
	while (line = get_next_line(map_fd))
	{
		ft_dprintf(STDOUT_FILENO, "%s", line);
		free(line);
	}
	return (close(map_fd), EXIT_FAILURE);
}
