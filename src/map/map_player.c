/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:06:32 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 19:02:57 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	set_player_angle(t_map *map, char c)
{
	if (c == 'N')
		map->player.angle = 90;
	else if (c == 'S')
		map->player.angle = 270;
	else if (c == 'E')
		map->player.angle = 180;
	else if (c == 'W')
		map->player.angle = 0;
}

static int	handle_player_at(t_map *map, int x, int y, char c)
{
	if (map->player.orientation != 0)
	{
		ft_putstr_fd("Error\nMultiple player positions found\n", 2);
		return (0);
	}
	map->player.x = (float)x;
	map->player.y = (float)y;
	map->player.orientation = c;
	set_player_angle(map, c);
	return (1);
}

static int	scan_row_for_player(t_map *map, t_string *row, int y)
{
	int	x;

	x = 0;
	while (row && x < (int)row->len && row->data[x])
	{
		if (is_player_char(row->data[x]))
		{
			if (!handle_player_at(map, x, y, row->data[x]))
				return (0);
		}
		x++;
	}
	return (1);
}

/*
** find_player:
**   Searches the entire map grid for the player's starting position.
**   Updates map->player and map->width according to the map content.
*/

bool	find_player(t_map *map)
{
	int			y;
	t_string	*row;
	int			w;

	y = 0;
	while (y < map->height)
	{
		row = (t_string *)ft_vec_get(&map->grid, y);
		if (!scan_row_for_player(map, row, y))
			return (false);
		w = (int)row->len;
		if (w > map->width)
			map->width = w;
		y++;
	}
	if (map->player.orientation == 0)
	{
		ft_putstr_fd("Error\nNo player position found\n", 2);
		return (false);
	}
	return (true);
}
