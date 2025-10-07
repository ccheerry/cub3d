/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:21:49 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 13:57:47 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** is_valid_line:
**   Checks if a map line contains only valid characters.
**   Allowed characters are:
**     - '0' (empty space)
**     - '1' (wall)
**     - 'N', 'S', 'E', 'W' (player starting positions)
**     - ' ' (space)
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
