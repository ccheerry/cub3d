/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:00:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

t_u128	ft_hash(t_u8 *__restrict__ bytes, size_t n)
{
	t_u128			hash;
	static t_u128	table[256] = {0};
	size_t			i;

	hash = HASH_SEED;
	i = 0;
	if (!table[0])
	{
		while (i < 256)
		{
			table[i] = ~(i << 8 | i << 16 | i << 32
					| (t_u128)i << 64) * HASH_PRIME;
			++i;
		}
	}
	i = 0;
	while (i++ < n)
	{
		hash ^= table[*bytes++];
		hash ^= hash << 64;
		hash = (hash << 5) | (hash >> (128 - 5));
	}
	return (hash);
}
