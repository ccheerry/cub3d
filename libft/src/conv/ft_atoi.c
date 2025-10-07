/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:57:08 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:57:09 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

// Modified to return -1 on unexpected chars etc

static bool	is_digit(const char *s, int i)
{
	if (!s || i < 0)
		return (false);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(const char *str)
{
	int		out;
	int		neg;
	int		i;

	out = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!is_digit(str, i))
		return (-1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		out = out * 10 + (str[i++] - '0');
	return (out * neg);
}
