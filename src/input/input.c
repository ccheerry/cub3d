/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:19:49 by albcamac          #+#    #+#             */
/*   Updated: 2025/09/30 17:42:22 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** is_wall:
**   Devuelve 1 si la celda (x, y) del mapa es un muro o está fuera de rango.
**   Devuelve 0 en caso contrario.
*/
static int	is_wall(t_map *m, int x, int y)
{
	t_string	*row;

	if (y < 0 || y >= m->height)
		return (1);
	row = (t_string *)ft_vec_get(&m->grid, y);
	if (!row || x < 0 || x >= (int)row->len)
		return (1);
	if (row->data[x] == '1')
		return (1);
	return (0);
}

/*
** get_block_bounds:
**   Calcula los límites de un rectángulo alrededor de la posición (x, y),
**   considerando el radio r y un pequeño padding contra paredes.
**   Los valores quedan guardados en la estructura t_bounds.
*/
static void	get_block_bounds(float x, float y, float r, t_bounds *b)
{
	double	rr;

	rr = (double)(r + WALL_PADDING);
	b->minx = (int)floor((double)x - rr);
	b->maxx = (int)floor((double)x + rr);
	b->miny = (int)floor((double)y - rr);
	b->maxy = (int)floor((double)y + rr);
}

/*
** rect_hits_wall:
**   Recorre las celdas dentro de un rectángulo (b) y devuelve 1 si
**   alguna corresponde a un muro, 0 si está libre.
*/
static int	rect_hits_wall(t_map *m, const t_bounds *b)
{
	int	i;
	int	j;

	j = b->miny;
	while (j <= b->maxy)
	{
		i = b->minx;
		while (i <= b->maxx)
		{
			if (is_wall(m, i, j))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

/*
** blocked_at:
**   Comprueba si la posición (x, y) con radio r colisiona con un muro.
**   Usa un rectángulo de colisión alrededor de la posición.
**   Devuelve 1 si bloqueado, 0 si libre.
*/
int	blocked_at(t_map *m, float x, float y, float r)
{
	t_bounds	b;

	get_block_bounds(x, y, r, &b);
	if (rect_hits_wall(m, &b))
		return (1);
	return (0);
}
