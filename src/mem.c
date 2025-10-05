/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:13:18 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/05 17:15:38 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_game *game)
{
	int	i;

	i = -1;
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
		// if (&game->door_tex)
		mlx_destroy_image(game->mlx, game->door_tex.img);
		free(game->doors);
		free(game->enemies);
		while (++i < ENEMY_FRAMES)
			mlx_destroy_image(game->mlx, game->enemy_anim.frames[i].img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		(mlx_destroy_display(game->mlx), free(game->mlx));
		game->mlx = NULL;
	}
}
