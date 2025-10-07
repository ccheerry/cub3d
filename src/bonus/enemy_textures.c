/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:08:46 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 17:02:27 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_one(t_game *g, t_img *dst, char *path)
{
	(void)g;
	return (load_texture(g, dst, path));
}

static char	*enemy_path(int i)
{
	if (i == 0)
		return ("textures/enemies/enemy_0.xpm");
	if (i == 1)
		return ("textures/enemies/enemy_1.xpm");
	if (i == 2)
		return ("textures/enemies/enemy_2.xpm");
	return ("textures/enemies/enemy_3.xpm");
}

int	load_enemy_textures(t_game *g)
{
	int		i;
	char	*path;

	i = 0;
	while (i < ENEMY_FRAMES)
	{
		path = enemy_path(i);
		if (!load_one(g, &g->enemy_anim.frames[i], path))
			return (0);
		i++;
	}
	g->enemy_anim.cur = 0;
	g->enemy_anim.ticks = 0;
	return (1);
}
