/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memst_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE inline void	_write_u8_fwd(void **__restrict__ dest,
	t_u8 x,
	size_t *__restrict__ n)
{
	t_u8	*wd;

	wd = *dest;
	while (*n >= sizeof(t_u8) * 2)
	{
		*wd++ = x;
		*wd++ = x;
		*n -= sizeof(t_u8) * 2;
	}
	while (*n >= sizeof(t_u8))
	{
		*wd++ = x;
		*n -= sizeof(t_u8);
	}
	*dest = wd;
}

FT_INLINE inline void	_write_u32_fwd(void **__restrict__ dest,
	t_u32 x,
	size_t *__restrict__ n)
{
	t_u32	*wd;

	wd = *dest;
	while (*n >= sizeof(t_u32) * 2)
	{
		*wd++ = x;
		*wd++ = x;
		*n -= sizeof(t_u32) * 2;
	}
	while (*n >= sizeof(t_u32))
	{
		*wd++ = x;
		*n -= sizeof(t_u32);
	}
	*dest = wd;
}

FT_INLINE inline void	_write_u64_fwd(void **__restrict__ dest,
	t_u64 x,
	size_t *__restrict__ n)
{
	t_u64	*wd;

	wd = *dest;
	while (*n >= sizeof(t_u64) * 2)
	{
		*wd++ = x;
		*wd++ = x;
		*n -= sizeof(t_u64) * 2;
	}
	while (*n >= sizeof(t_u64))
	{
		*wd++ = x;
		*n -= sizeof(t_u64);
	}
	*dest = wd;
}

FT_INLINE inline void	_write_u128_fwd(void **__restrict__ dest,
	t_u128 x,
	size_t *__restrict__ n)
{
	t_u64	*wd;

	wd = *dest;
	while (*n >= sizeof(t_u64) * 2)
	{
		*wd++ = x;
		*wd++ = x;
		*n -= sizeof(t_u64) * 2;
	}
	while (*n >= sizeof(t_u64))
	{
		*wd++ = x;
		*n -= sizeof(t_u64);
	}
	*dest = wd;
}
