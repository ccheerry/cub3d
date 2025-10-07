/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:28:58 by albcamac          #+#    #+#             */
/*   Updated: 2025/09/30 17:26:03 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** parse_color (función auxiliar privada):
**   Convierte una cadena con formato "R,G,B" en tres enteros.
**   Valida que los valores estén en el rango [0, 255].
**   Devuelve 1 si es válido, 0 si falla el parseo o el rango.
*/
static int	parse_color(char *str, int *r, int *g, int *b)
{
	char	**parts;

	parts = ft_split(str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
	{
		ft_putstr_fd("Error\nInvalid color format (must be R,G,B)\n", 2);
		if (parts)
			ft_free_array((void ***)&parts);
		return (0);
	}
	*r = ft_atoi(parts[0]);
	*g = ft_atoi(parts[1]);
	*b = ft_atoi(parts[2]);
	ft_free_array((void ***)&parts);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
	{
		ft_putstr_fd("Error\nColor values must be in range [0-255]\n", 2);
		return (0);
	}
	return (1);
}

/*
** apply_color:
**   Aplica un color al mapa dependiendo de la clave:
**   - "F": asigna el color del suelo.
**   - "C": asigna el color del techo.
**   Devuelve 1 si se asignó correctamente, 0 en caso de error.
*/
int	apply_color(t_map *map, char *key, char *value)
{
	int	result;

	result = 0;
	if (ft_strcmp(key, "F") == 0)
	{
		if (map->colors.floor_r >= 0)
			return (ft_putstr_fd("Error\nDuplicate floor color (F)\n", 2), 0);
		result = parse_color(value, &map->colors.floor_r,
				&map->colors.floor_g, &map->colors.floor_b);
	}
	else if (ft_strcmp(key, "C") == 0)
	{
		if (map->colors.ceiling_r >= 0)
			return (ft_putstr_fd("Error\nDuplicate ceiling color (C)\n", 2),
				0);
		result = parse_color(value, &map->colors.ceiling_r,
				&map->colors.ceiling_g, &map->colors.ceiling_b);
	}
	return (result);
}
