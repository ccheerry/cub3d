/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:13:18 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/15 17:37:27 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_game *game)
{
	if (game->mlx)
	{
		if (game->map.textures.north)
		{
			mlx_destroy_image(game->mlx, game->map.textures.north);
			game->map.textures.north = NULL;
		}
		if (game->map.textures.south)
		{
			mlx_destroy_image(game->mlx, game->map.textures.south);
			game->map.textures.south = NULL;
		}
		if (game->map.textures.east)
		{
			mlx_destroy_image(game->mlx, game->map.textures.east);
			game->map.textures.east = NULL;
		}
		if (game->map.textures.west)
		{
			mlx_destroy_image(game->mlx, game->map.textures.west);
			game->map.textures.west = NULL;
		}
		(mlx_destroy_display(game->mlx), free(game->mlx));
		game->mlx = NULL;
	}
}
