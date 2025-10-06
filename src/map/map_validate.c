/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:21:49 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/01 21:56:16 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** is_valid_line:
**   Comprueba si una línea del mapa contiene únicamente caracteres válidos.
**   Los caracteres permitidos son:
**     - '0' (espacio vacío)
**     - '1' (muro)
**     - 'N', 'S', 'E', 'W' (posiciones iniciales del jugador)
**     - ' ' (espacio)
**   Devuelve true si la línea es válida, false si encuentra algún
**   carácter no permitido.
*/
bool	is_valid_line(char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'D'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != 'X')
			return (false);
		i = i + 1;
	}
	return (true);
}
