/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:17:50 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 19:47:28 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** create_frame:
**   Creates a new rendering image in memory using MiniLibX.
**   Initializes the `frame` structure with buffer, size and format.
**   Returns 1 on success, 0 on error.
*/
static int	create_frame(t_game *g, int w, int h)
{
	g->frame.img = mlx_new_image(g->mlx, w, h);
	if (!g->frame.img)
		return (0);
	g->frame.addr = mlx_get_data_addr(g->frame.img, &g->frame.bpp,
			&g->frame.line_len, &g->frame.endian);
	g->frame.w = w;
	g->frame.h = h;
	if (!g->frame.addr)
		return (0);
	return (1);
}

/*
** start_window:
**   Creates the main game window and framebuffer.
**   Initializes player movement and rotation speed.
**   Registers keyboard, close and loop rendering hooks.
**   Returns 1 on success, 0 on error.
*/
int	start_window(t_game *g)
{
	g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!g->win)
		return (0);
	if (!create_frame(g, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (0);
	mouse_init(g);
	g->move_speed = 0.022f;
	g->rot_speed = 0.7f * M_PI / 180.0f;
	mlx_hook(g->win, 6, 1L << 6, mouse_move_hook, g);
	mlx_hook(g->win, ON_KEYDOWN, MASK_KEYPRESS, on_key_press, g);
	mlx_hook(g->win, ON_KEYUP, MASK_KEYRELEASE, on_key_release, g);
	mlx_hook(g->win, ON_DESTROY, MASK_STRUCT, on_close, g);
	mlx_loop_hook(g->mlx, render_frame, g);
	return (1);
}

/*
** on_close:
**   Callback for when the window is closed or ESC is pressed.
**   Frees window, map and game memory, and terminates the process.
*/
int	on_close(t_game *g)
{
	mlx_mouse_show(g->mlx, g->win);
	free_mlx(g);
	free_map(&g->map);
	free(g);
	exit(0);
	return (0);
}
