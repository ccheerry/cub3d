/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:17:50 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 01:38:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** create_frame:
**   Crea una nueva imagen de renderizado en memoria usando MiniLibX.
**   Inicializa la estructura `frame` con el buffer, tamaño y formato.
**   Devuelve 1 en éxito, 0 en caso de error.
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
**   Crea la ventana principal del juego y el framebuffer.
**   Inicializa la velocidad de movimiento y rotación del jugador.
**   Registra los hooks de teclado, cierre y renderizado en bucle.
**   Devuelve 1 en éxito, 0 en caso de error.
*/
int	start_window(t_game *g)
{
	g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!g->win)
		return (0);
	if (!create_frame(g, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (0);
	mlx_do_key_autorepeatoff(g->mlx);
	mouse_init(g);
	g->move_speed = 0.07f;
	g->rot_speed = 2.5f * M_PI / 180.0f;
	mlx_hook(g->win, 6, 1L << 6, mouse_move_hook, g);
	mlx_hook(g->win, ON_KEYDOWN, MASK_KEYPRESS, on_key_press, g);
	mlx_hook(g->win, ON_KEYUP, MASK_KEYRELEASE, on_key_release, g);
	mlx_hook(g->win, ON_DESTROY, MASK_STRUCT, on_close, g);
	mlx_loop_hook(g->mlx, render_frame, g);
	return (1);
}

/*
** on_close:
**   Callback para cuando se cierra la ventana o se pulsa ESC.
**   Libera memoria de la ventana, mapa y juego, y termina el proceso.
*/
int	on_close(t_game *g)
{
	mlx_mouse_show(g->mlx, g->win);
	mlx_do_key_autorepeaton(g->mlx);
	free_mlx(g);
	free_map(&g->map);
	free(g);
	exit(0);
	return (0);
}
