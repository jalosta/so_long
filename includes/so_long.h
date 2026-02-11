/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:27:49 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/11 15:22:57 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libftdprintf.h"
# include <errno.h>
# include <fcntl.h>   // open, close
# include <math.h>    // https://linux.die.net/man/3/math
# include <stdbool.h> // boolean
# include <stdio.h>   // perror
# include <stdlib.h>  // malloc, exit
# include <string.h>  // strerror
# include <unistd.h>  // write

# define OPEN_FAIL -1
# define TILE 48
# define WALL 49
# define COLLECTIBLE 67
# define MAP_EXIT 69
# define PLAYER 80
# define PARSE_FAILURE -1

typedef struct s_map_dimensions
{
	unsigned int	x;
	unsigned int	y;
}					t_map_dimensions;

#endif