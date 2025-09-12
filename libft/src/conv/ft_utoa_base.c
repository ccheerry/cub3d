/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

static size_t	count(size_t n, size_t blen)
{
	size_t	c;

	c = 0;
	while (n != 0)
	{
		c++;
		n /= blen;
	}
	return (c);
}

static ssize_t	ft_ftalidate_base(char *base)
{
	char	*ptr;
	ssize_t	l;

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

char	*ft_utoa_base(size_t n, char *base)
{
	size_t		blen;
	ssize_t		blen1;
	char		*out;
	size_t		c;

	blen1 = ft_ftalidate_base(base);
	if (blen1 == -1)
		return (NULL);
	blen = (size_t) blen1;
	if (n == 0)
		return (ft_strdup("0"));
	out = ft_alloc(count(n, blen) + 1);
	if (!out)
		return (NULL);
	c = count(n, blen);
	out[c] = 0;
	while (n != 0)
	{
		out[--c] = base[n % blen];
		n /= blen;
	}
	if (c == 1)
		out[--c] = '-';
	return (out);
}
