/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:54:00 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:54:28 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_len(t_string *row, size_t *len)
{
	*len = 0;
	if (row)
		*len = row->len;
	if (*len && row->data[*len - 1] == '\n')
		(*len)--;
}

void	set_enemy(t_enemy *e, size_t x, size_t y)
{
	e->x = (float)x + 0.5f;
	e->y = (float)y + 0.5f;
}

void	fill_row_enemies(t_string *row, size_t y, t_enemy *list, int *i)
{
	size_t	x;
	size_t	len;

	fill_len(row, &len);
	x = 0;
	while (row && x < len)
	{
		if (row->data[x] == 'X')
		{
			set_enemy(&list[*i], x, y);
			row->data[x] = '0';
			(*i)++;
		}
		x++;
	}
}
