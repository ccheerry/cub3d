/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

float	ft_floorf(float x)
{
	long long	i;

	i = (long long)x;
	if ((float)i > x)
		return (i - 1);
	return (i);
}

float	ft_ceilf(float x)
{
	long long	i;

	i = (long long)x;
	if ((float)i < x)
		return (i + 1);
	return (i);
}

float	ft_roundf(float x, t_u8 n)
{
	float	p10;

	if (n > 7)
		n = 7;
	p10 = 0.1f;
	while (n--)
		p10 *= 10.0f;
	if (x >= 0)
		return (ft_floorf(x * p10 + 0.5f) / p10);
	else
		return (ft_ceilf(x * p10 - 0.5f) / p10);
}

float	ft_roundff(float x)
{
	if (x >= 0.0f)
		return ((float)((int)(x + 0.5f)));
	else
		return ((float)((int)(x - 0.5f)));
}
