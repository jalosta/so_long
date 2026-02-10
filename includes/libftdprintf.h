/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftdprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:37:53 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/10 09:45:46 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTDPRINTF_H
# define LIBFTDPRINTF_H

# include "libft.h"
# include <stdarg.h> // va_list and macros

int	ft_dprintf(int fd, const char *format, ...);

#endif