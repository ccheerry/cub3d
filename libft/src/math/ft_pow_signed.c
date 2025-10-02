/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	ft_ipow(int x, t_u64 n)
{
	int	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

long long	ft_lpow(long long x, t_u64 n)
{
	long long	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

float	ft_fpow(float x, t_u64 n)
{
	float	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

double	ft_dpow(double x, t_u64 n)
{
	double	res;

	res = 1.0;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}
