/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:37:47 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/17 16:48:26 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	handle_format(const char format, va_list ap, int fd)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(ap, int), fd));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(ap, const char *), fd));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), fd));
	else
		return (ft_putchar_fd('%', fd));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;
	int		e_check;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (va_end(ap), count);
			e_check = handle_format(*format, ap, fd);
		}
		else
			e_check = ft_putchar_fd(*format, fd);
		if (e_check == WRITE_FAIL)
			return (va_end(ap), WRITE_FAIL);
		count += e_check;
		format++;
	}
	va_end(ap);
	return (count);
}
