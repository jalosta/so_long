/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:33:00 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/10 09:47:30 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	count;
	int	e_check;

	count = 0;
	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	while (*s)
	{
		e_check = ft_putchar_fd(*s, fd);
		if (e_check == WRITE_FAIL)
			return (WRITE_FAIL);
		count += e_check;
		s++;
	}
	return (count);
}
