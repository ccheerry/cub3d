/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline int	_lookup_u32(t_u32 word, t_u32 mask)
{
	t_u32	diff;
	t_u32	t;

	t = (t_u128)0;
	diff = word ^ mask;
	t = (diff - LONES_32) & ~diff & HIGHS_32;
	if (!t)
		return (-1);
	return (ft_memctz_u32(t) >> 3);
}

inline int	_lookup_u64(t_u64 word, t_u64 mask)
{
	t_u64	diff;
	t_u64	t;

	t = (t_u128)0;
	diff = word ^ mask;
	t = (diff - LONES_64) & ~diff & HIGHS_64;
	if (!t)
		return (-1);
	return (ft_memctz_u64(t) >> 3);
}

inline int	_lookup_u128(t_u128 word, t_u128 mask)
{
	int		lkup;
	t_u64	low_word;
	t_u64	high_word;
	t_u64	low_mask;
	t_u64	high_mask;

	high_mask = (t_u64)(mask >> 64);
	low_mask = (t_u64)mask;
	high_word = (t_u64)(word >> 64);
	low_word = (t_u64)word;
	lkup = _lookup_u64(low_word, low_mask);
	if (lkup != -1)
		return (lkup);
	lkup = _lookup_u64(high_word, high_mask);
	if (lkup != -1)
		return (64 + lkup);
	return (-1);
}
