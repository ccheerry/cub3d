/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

int	ft_strcmp(const char *a, const char *b)
{
	size_t	c;

	if ((!a && b) || (a && !b))
		return (-1);
	if (!a && !b)
		return (0);
	c = 0;
	while (a[c] && b[c])
	{
		if (a[c] != b[c])
			return (a[c] - b[c]);
		c++;
	}
	return (a[c] - b[c]);
}
