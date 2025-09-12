/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

static unsigned int	_abs(int n)
{
	if (n < 0)
		return ((unsigned int)-n);
	return ((unsigned int)n);
}

static size_t	count(int n, int blen)
{
	size_t	c;

	c = 0;
	if (n < 0)
		c++;
	while (n != 0)
	{
		c++;
		n /= blen;
	}
	return (c);
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

char	*ft_itoa_base(int n, char *base)
{
	int			blen;
	char		*out;
	size_t		c;

	blen = ft_ftalidate_base(base);
	if (blen == -1)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	out = ft_alloc(count(n, blen) + 1);
	if (!out)
		return (NULL);
	c = count(n, blen);
	out[c] = 0;
	while (n != 0)
	{
		out[--c] = base[_abs(n % blen)];
		n /= blen;
	}
	if (c == 1)
		out[--c] = '-';
	return (out);
}
