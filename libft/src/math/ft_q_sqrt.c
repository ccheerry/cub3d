/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_q_sqrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

float	ft_q_sqrt(float number)
{
	long		i;
	float		x2;
	float		y;
	float		threehalfs;

	if (number < 0)
		return (-1);
	threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	ft_memcpy(&i, &y, sizeof(float));
	i = 0x5f3759df - (i >> 1);
	ft_memcpy(&y, &i, sizeof(float));
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return (number * y);
}

float	ft_q_sqrt_round(float number, t_u8 n)
{
	return (ft_roundf(ft_q_sqrt(number), n));
}

float	ft_q_sqrt_fround(float number)
{
	return (ft_roundff(ft_q_sqrt(number)));
}
