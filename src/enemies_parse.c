/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:08:14 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:35:36 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_enemies_grid(t_game *g, int *count)
{
	size_t		y;
	size_t		x;
	size_t		len;
	t_string	*row;

	*count = 0;
	y = 0;
	while (y < g->map.grid.size)
	{
		row = (t_string *)ft_vec_get(&g->map.grid, y);
		if (!row)
			return (0);
		len = row->len;
		if (len && row->data[len - 1] == '\n')
			len--;
		x = 0;
		while (x < len)
		{
			if (row->data[x] == 'X')
				(*count)++;
			x++;
		}
		y++;
	}
	return (1);
}

static void	set_enemy(t_enemy *e, size_t x, size_t y)
{
	e->x = (float)x + 0.5f;
	e->y = (float)y + 0.5f;
}

static int	fill_enemies_grid(t_game *g, t_enemy *list)
{
	size_t		y;
	size_t		x;
	size_t		len;
	int			i;
	t_string	*row;

	i = 0;
	y = 0;
	while (y < g->map.grid.size)
	{
		row = (t_string *)ft_vec_get(&g->map.grid, y);
		len = row ? row->len : 0;
		if (len && row->data[len - 1] == '\n')
			len--;
		x = 0;
		while (row && x < len)
		{
			if (row->data[x] == 'X')
			{
				set_enemy(&list[i], x, y);
				row->data[x] = '0';
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	find_enemies(t_game *g)
{
	int		n;
	t_enemy	*arr;

	if (!count_enemies_grid(g, &n))
		return (0);
	if (n == 0)
	{
		g->enemies = 0;
		g->enemy_count = 0;
		return (1);
	}
	arr = (t_enemy *)ft_calloc(n, sizeof(t_enemy));
	if (!arr)
		return (0);
	if (!fill_enemies_grid(g, arr))
		return (free(arr), 0);
	g->enemies = arr;
	g->enemy_count = n;
	return (1);
}
