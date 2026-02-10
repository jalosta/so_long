/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:33:00 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/10 10:51:12 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;
	int	e_check;

	count = 0;
	if (n > 9)
		ft_putunbr_fd(n / 10, fd);
	e_check = ft_putchar("0123456789"[n % 10]);
	if (e_check == WRITE_FAIL)
		return (WRITE_FAIL);
	count += e_check;
	return (count);
}
