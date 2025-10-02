/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:21:12 by albcamac          #+#    #+#             */
/*   Updated: 2025/09/30 16:21:14 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	size_t		i;
	t_string	*ptr;

	if (map->grid.data)
	{
		i = 0;
		while (i < map->grid.size)
		{
			ptr = (t_string *)ft_vec_get(&map->grid, i);
			if (ptr)
				ft_tstr_free(ptr);
			i = i + 1;
		}
		ft_vec_free(&map->grid);
	}
	ft_tstr_free(&map->textures.north_path);
	ft_tstr_free(&map->textures.south_path);
	ft_tstr_free(&map->textures.east_path);
	ft_tstr_free(&map->textures.west_path);
}
