/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:08:45 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 14:11:35 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** rgb:
**   Converts three color components (R,G,B) into a single integer value
**   in 0xRRGGBB format that can be used to paint pixels.
*/

int	rgb(int r, int g, int b)
{
	return (((r & 255) << 16) | ((g & 255) << 8) | (b & 255));
}

/*
** put_pixel:
**   Paints a pixel at position (x,y) of the image with the given color.
*/

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (!img || x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

/*
** clear_sky_floor:
**   Fills the frame buffer with two colors:
**   - The upper half with the ceiling color (sky).
**   - The lower half with the floor color.
*/

void	clear_sky_floor(t_game *g)
{
	int	y;
	int	x;
	int	sky;
	int	floorc;

	y = 0;
	sky = rgb(g->map.colors.ceiling_r, g->map.colors.ceiling_g,
			g->map.colors.ceiling_b);
	floorc = rgb(g->map.colors.floor_r, g->map.colors.floor_g,
			g->map.colors.floor_b);
	while (y < g->frame.h)
	{
		x = 0;
		while (x < g->frame.w)
		{
			if (y < g->frame.h / 2)
				put_pixel(&g->frame, x, y, sky);
			else
				put_pixel(&g->frame, x, y, floorc);
			x++;
		}
		y++;
	}
}

/*
** render_frame:
**   Updates the player's position, clears the background with sky/floor
**   and casts a ray for each screen column to render the world.
**   Finally, displays the frame in the window.
*/

int	render_frame(t_game *g)
{
	int	x;

	update_player(g);
	update_doors(g);
	clear_sky_floor(g);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		cast_one_column(g, x);
		x++;
	}
	render_enemies(g);
	minimap_render(g);
	mlx_put_image_to_window(g->mlx, g->win, g->frame.img, 0, 0);
	return (0);
}
