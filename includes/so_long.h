/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:27:49 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/23 16:11:48 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_dprintf.h"
# include "get_next_line_trimmed.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h> // open, close
# include <math.h>  // https://linux.die.net/man/3/math
# include <mlx.h>
# include <stdbool.h> // boolean
# include <stdlib.h>  // malloc, exit
# include <string.h>  // strerror
# include <unistd.h>  // write

# define OPEN_FAIL -1
# define WALL '1'
# define EMPTY_SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define START 'P'
# define TILE_SIZE 32
# define KEY_ESC 65307
# define EVENT_KEY_PRESS 2
# define EVENT_DESTROY 17

typedef enum e_map_errors
{
	MAP_ERR_UNEVEN_LEN = 1 >> 0,
	MAP_ERR_AGAPE = 1 << 1,
	MAP_ERR_NO_VALID_EXIT = 1 << 2,
	MAP_ERR_NO_VALID_START = 1 << 3,
	MAP_ERR_NO_COLLECTIBLE = 1 << 4,
	MAP_ERR_NO_VALID_PATH = 1 << 5
}			t_map_errors;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_point	size;
}			t_img;

typedef struct s_game
{
	char	**map;
	t_point	map_size;
	t_point	current_co;
	int		collectibles;
	int		moves;
	t_img	space;
	t_img	wall;
	t_img	collect;
	t_img	exit;
	t_img	player;
}			t_game;

void		print_err(char *msg);
void		print_err_list(char errors);
void		load_map(char *file, t_game *ctx);
char		validate_row_lengths(char **map, t_game *ctx);
char		validate_walls(char **map, t_game *ctx);
char		validate_unique_passage(char **map, char passage);
char		count_collectibles(char **map, t_game *ctx);
bool		is_navigable(char **tab, t_point size);
void		flood_fill(char **tab, t_point size, t_point begin);
void		free_arrays(char **arrays);
void		set_error_if(bool valid, char *error, char mask);

#endif