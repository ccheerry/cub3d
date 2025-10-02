/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:40:33 by albcamac          #+#    #+#             */
/*   Updated: 2025/09/30 17:23:39 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** on_key_press:
**   Maneja la pulsación de teclas.
**   Activa la bandera correspondiente en la estructura de teclas del juego.
**   Devuelve siempre 0 (necesario para MLX hooks).
*/
int	on_key_press(int key, t_game *g)
{
	if (key == KEY_W)
		g->keys.w = true;
	else if (key == KEY_S)
		g->keys.s = true;
	else if (key == KEY_A)
		g->keys.a = true;
	else if (key == KEY_D)
		g->keys.d = true;
	else if (key == KEY_LEFT)
		g->keys.left = true;
	else if (key == KEY_RIGHT)
		g->keys.right = true;
	else if (key == KEY_ESC)
		g->keys.esc = true;
	return (0);
}

/*
** on_key_release:
**   Maneja la liberación de teclas.
**   Desactiva la bandera correspondiente en la estructura de teclas del juego.
**   Devuelve siempre 0 (necesario para MLX hooks).
*/
int	on_key_release(int key, t_game *g)
{
	if (key == KEY_W)
		g->keys.w = false;
	else if (key == KEY_S)
		g->keys.s = false;
	else if (key == KEY_A)
		g->keys.a = false;
	else if (key == KEY_D)
		g->keys.d = false;
	else if (key == KEY_LEFT)
		g->keys.left = false;
	else if (key == KEY_RIGHT)
		g->keys.right = false;
	else if (key == KEY_ESC)
		g->keys.esc = false;
	return (0);
}
