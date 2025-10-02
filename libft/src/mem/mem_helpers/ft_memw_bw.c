/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memw_bw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline void	_copy_u8_bw(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u8	*bd;
	t_u8	*bs;

	bd = *dest;
	bs = (t_u8 *)*src;
	while ((*n)--)
		*bd-- = *bs--;
}

inline void	_copy_u32_bw(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u32	*wd;
	t_u32	*ws;

	wd = *dest;
	ws = (t_u32 *)*src;
	while (*n >= sizeof(t_u32) * 2)
	{
		*wd-- = *ws--;
		*wd-- = *ws--;
		*n -= sizeof(t_u32) * 2;
	}
	while (*n >= sizeof(t_u32))
	{
		*wd-- = *ws--;
		*n -= sizeof(t_u32);
	}
	*dest = wd;
	*src = ws;
}

inline void	_copy_u64_bw(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u64	*wd;
	t_u64	*ws;

	wd = *dest;
	ws = (t_u64 *)*src;
	while (*n >= sizeof(t_u64) * 2)
	{
		*wd-- = *ws--;
		*wd-- = *ws--;
		*n -= sizeof(t_u64) * 2;
	}
	while (*n >= sizeof(t_u64))
	{
		*wd-- = *ws--;
		*n -= sizeof(t_u64);
	}
	*dest = wd;
	*src = ws;
}

inline void	_copy_u128_bw(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u128	*wd;
	t_u128	*ws;

	wd = *dest;
	ws = (t_u128 *)*src;
	while (*n >= sizeof(t_u128) * 2)
	{
		*wd-- = *ws--;
		*wd-- = *ws--;
		*n -= sizeof(t_u128) * 2;
	}
	while (*n >= sizeof(t_u128))
	{
		*wd-- = *ws--;
		*n -= sizeof(t_u128);
	}
	*dest = wd;
	*src = ws;
}
