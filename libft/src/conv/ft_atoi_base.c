/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

static int	ft_check_in_base(char c, char *base)
{
	int	pos;

	pos = 0;
	while (*base)
	{
		if (*base++ == c)
			return (pos);
		pos++;
	}
	return (-1);
}

static int	ft_ftalidate_base(char *base)
{
	char	*ptr;
	int		l;

	l = ft_strlen(base);
	ptr = base;
	if (l < 2)
		return (-1);
	while (*base)
	{
		ptr = base + 1;
		while (*ptr)
			if (*base == *ptr++
				|| *base == '-'
				|| *base == '+')
				return (-1);
		base++;
	}
	return (l);
}

int	ft_atoi_base(char *str, char *base, int base_len)
{
	int				out;
	int				neg;

	if (base_len == -1 || ft_ftalidate_base(base) == -1)
		return (0);
	out = 0;
	neg = 1;
	if (!*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (ft_check_in_base(*str, base) >= 0)
		out = out * base_len + ft_check_in_base(*str++, base);
	return (out * neg);
}
