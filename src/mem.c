/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:13:18 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/26 15:21:03 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_game *game)
{
	if (game->mlx)
	{
		if (game->frame.img)
			mlx_destroy_image(game->mlx, game->frame.img);
		if (game->map.textures.north.img)
			mlx_destroy_image(game->mlx, game->map.textures.north.img);
		if (game->map.textures.south.img)
			mlx_destroy_image(game->mlx, game->map.textures.south.img);
		if (game->map.textures.east.img)
			mlx_destroy_image(game->mlx, game->map.textures.east.img);
		if (game->map.textures.west.img)
			mlx_destroy_image(game->mlx, game->map.textures.west.img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		(mlx_destroy_display(game->mlx), free(game->mlx));
		game->mlx = NULL;
	}
}
