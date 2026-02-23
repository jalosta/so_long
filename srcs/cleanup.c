/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:37:28 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/23 13:18:29 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arrays(char **arrays)
{
	size_t	i;

	i = 0;
	while (arrays[i] != NULL)
	{
		free(arrays[i]);
		i++;
	}
	if (arrays)
		free(arrays);
}
