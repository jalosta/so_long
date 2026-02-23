/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:37:48 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/23 16:22:57 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_or_exit(t_game *ctx)
{
	char	e_mask;

	e_mask = 0;
	e_mask |= validate_row_lengths(ctx->map, ctx);
	e_mask |= validate_walls(ctx->map, ctx);
	e_mask |= validate_unique_passage(ctx->map, EXIT);
	e_mask |= validate_unique_passage(ctx->map, START);
	e_mask |= count_collectibles(ctx->map, ctx);
	if (e_mask)
	{
		free_arrays(ctx->map);
		print_err_list(e_mask);
	}
	else
	{
		if (false == is_navigable(ctx->map, ctx->map_size))
		{
			free_arrays(ctx->map);
			print_err_list(MAP_ERR_NO_VALID_PATH);
		}
	}
}

int	main(int ac, char **av)
{
	t_game	ctx;
	void	*mlx;
	void	*win;

	if (ac != 2)
		return (print_err(strerror(EINVAL)), EXIT_FAILURE);
	load_map(av[1], &ctx);
	if (ctx.map == NULL)
		return (print_err("Empty map"), EXIT_FAILURE);
	validate_or_exit(&ctx);
	free_arrays(ctx.map);
	return (EXIT_SUCCESS);
}
