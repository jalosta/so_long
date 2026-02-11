/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:35:38 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/11 15:23:58 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h> // malloc, free
# include <unistd.h> // read

# define READ_ERROR -1
# define END_OF_FILE 0
# define INFINITE_LOOP 1
# define BUFFER_SIZE 1024

char				*get_next_line(int fd);

#endif