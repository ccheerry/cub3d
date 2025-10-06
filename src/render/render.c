/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:08:45 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/06 21:10:41 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** rgb:
**   Convierte tres componentes de color (R,G,B) en un valor entero único
**   en formato 0xRRGGBB que puede usarse para pintar píxeles.
*/
int	rgb(int r, int g, int b)
{
	return (((r & 255) << 16) | ((g & 255) << 8) | (b & 255));
}

/*
** put_pixel:
**   Pinta un píxel en la posición (x,y) de la imagen indicada con el color dado.
**   Comprueba límites para no escribir fuera de la memoria de la imagen.
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
**   Rellena el frame buffer con dos colores:
**   - La mitad superior con el color del techo (sky).
**   - La mitad inferior con el color del suelo (floor).
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
**   Actualiza la posición del jugador, limpia el fondo con cielo/suelo
**   y lanza un rayo por cada columna de la pantalla para renderizar el mundo.
**   Finalmente, muestra el frame en la ventana con MiniLibX.
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
