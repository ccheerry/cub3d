/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:40:33 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 14:05:47 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
