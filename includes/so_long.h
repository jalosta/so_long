/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:27:49 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/12 02:02:12 by jalosta-         ###   ########.fr       */
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

typedef enum e_map_errors
{
	MAP_ERR_EMPTY = 1 << 0,
	MAP_ERR_NOT_RECTANGULAR = 1 << 1,
	MAP_ERR_NOT_ENCLOSED = 1 << 2,
	MAP_ERR_NO_EXIT = 1 << 3,
	MAP_ERR_NO_START = 1 << 4,
	MAP_ERR_NO_COLLECTIBLE = 1 << 5,
}	t_map_errors;

# define OPEN_FAIL -1
# define WALL '1'
# define TILE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define START 'P'

#endif