/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_surround.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:06:04 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 13:56:57 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** is_map_line:
**   Checks if a line belongs to the map.
**   Returns 1 if it contains valid map characters
**   (0, 1, N, S, E, W or spaces).
*/

int	is_map_line(char *line)
{
	int		i;
	int		has_map_char;

	if (!line || line[0] == '\0')
		return (0);
	i = 0;
	has_map_char = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'D'
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'X'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
		{
			if (line[i] != ' ')
				has_map_char = 1;
		}
		else
			return (0);
		i++;
	}
	return (has_map_char);
}

/*
** get_char_at:
**   Returns the character at position x of a row.
*/

static char	get_char_at(t_string *row, int x)
{
	if (!row || x < 0 || x >= (int)row->len)
		return ('\0');
	return (row->data[x]);
}

/*
** cell_requires_wall:
**   Indicates if a cell (0 or player) must be surrounded by valid walls.
*/

static int	cell_requires_wall(t_string *row, int x)
{
	char	c;

	if (!row || x < 0 || x >= (int)row->len)
		return (0);
	c = row->data[x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
** neighbors_invalid:
**   Checks if around a walkable cell there are empty spaces
**   or invalid characters (spaces, '\0', '\n').
*/

static int	neighbors_invalid(t_map *map, int y, int x)
{
	t_string	*row;
	char		ch;

	row = (t_string *)ft_vec_get(&map->grid, y);
	ch = get_char_at((t_string *)ft_vec_get(&map->grid, y - 1), x);
	if (ch == ' ' || ch == '\0' || ch == '\n')
		return (1);
	ch = get_char_at((t_string *)ft_vec_get(&map->grid, y + 1), x);
	if (ch == ' ' || ch == '\0' || ch == '\n')
		return (1);
	if (get_char_at(row, x - 1) == ' ' || get_char_at(row, x + 1) == ' '
		|| get_char_at(row, x - 1) == '\0' || get_char_at(row, x + 1) == '\0'
		|| get_char_at(row, x - 1) == '\n' || get_char_at(row, x + 1) == '\n')
		return (1);
	return (0);
}

bool	is_map_surrounded(t_map *map)
{
	int			y;
	int			x;
	t_string	*row;

	y = 0;
	while (y < map->height)
	{
		row = (t_string *)ft_vec_get(&map->grid, y);
		x = 0;
		while (row && x < (int)row->len)
		{
			if (cell_requires_wall(row, x))
			{
				if (y == 0 || y == map->height - 1)
					return (ft_putstr_fd("Error\nMap not closed: "
							"walkable cell on border\n", 2), false);
				if (neighbors_invalid(map, y, x))
					return (ft_putstr_fd("Error\nMap not closed: "
							"walkable cell exposed to void\n", 2), false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
