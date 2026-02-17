/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:27:49 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/17 16:42:53 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "flood_fill.h"
# include "ft_dprintf.h"
# include "get_next_line_trimmed.h"
# include <errno.h>
# include <fcntl.h>   // open, close
# include <math.h>    // https://linux.die.net/man/3/math
# include <stdbool.h> // boolean
# include <stdio.h>   // perror
# include <stdlib.h>  // malloc, exit
# include <string.h>  // strerror
# include <unistd.h>  // write

typedef enum e_map_errors
{
	MAP_ERR_EMPTY = 1 << 0,
	MAP_ERR_NOT_RECTANGULAR = 1 << 1,
	MAP_ERR_NOT_ENCLOSED = 1 << 2,
	MAP_ERR_NO_SINGLE_EXIT = 1 << 3,
	MAP_ERR_NO_SINGLE_START = 1 << 4,
	MAP_ERR_NO_COLLECTIBLE = 1 << 5,
	MAP_ERR_NO_VALID_PATH = 1 << 6
}		t_map_errors;

typedef struct s_data
{
	char	error;
	t_list	*map;
	size_t	width;
	size_t	height;
	char	*tab;
}	t_data;

# define OPEN_FAIL -1
# define WALL '1'
# define TILE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define START 'P'

char	evaluate_map(int map_fd);
bool	is_rectangular(t_list *map, size_t ref_len);
bool	is_enclosed(t_list *map, size_t width);
bool	has_passage(t_list *map, char passage);
bool	has_collectible(t_list *map);
bool	is_navigable(char **tab);

#endif