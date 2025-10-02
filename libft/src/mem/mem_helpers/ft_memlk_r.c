/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlk_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE inline void	*_look4_u8_fwd_unsafe(void *__restrict__ ptr,
	t_u8 x,
	size_t *__restrict__ i)
{
	t_u8	*d;

	d = (t_u8 *) ptr + *i;
	while (1)
	{
		if (*d++ == x)
			break ;
		(*i)++;
		if (*d++ == x)
			break ;
		(*i)++;
	}
	return ((t_u8 *)d - 1);
}

FT_INLINE inline void	*_look4_u32_fwd(void *__restrict__ ptr,
	t_u32 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	t_u32	*d;
	int		lk;

	d = (t_u32 *) ptr + *i;
	while (*n >= sizeof(t_u32) * 2)
	{
		lk = _lookup_u32(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u32) + lk);
		lk = _lookup_u32(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u32) + lk);
		*n -= sizeof(t_u32) * 2;
		*i += sizeof(t_u32) * 2;
	}
	while (*n >= sizeof(t_u32))
	{
		lk = _lookup_u32(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u32) + lk);
		*n -= sizeof(t_u32);
		*i += sizeof(t_u32);
	}
	return (NULL);
}

FT_INLINE inline void	*_look4_u64_fwd(void *__restrict__ ptr,
	t_u64 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	t_u64	*d;
	int		lk;

	d = (t_u64 *) ptr + *i;
	while (*n >= sizeof(t_u64) * 2)
	{
		lk = _lookup_u64(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u64) + lk);
		lk = _lookup_u64(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u64) + lk);
		*n -= sizeof(t_u64) * 2;
		*i += sizeof(t_u64) * 2;
	}
	while (*n >= sizeof(t_u64))
	{
		lk = _lookup_u64(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u64) + lk);
		*n -= sizeof(t_u64);
		*i += sizeof(t_u64);
	}
	return (NULL);
}

FT_INLINE inline void	*_look4_u128_fwd(void *__restrict__ ptr,
	t_u128 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	t_u128	*d;
	int		lk;

	d = (t_u128 *) ptr + *i;
	while (*n >= sizeof(t_u128) * 2)
	{
		lk = _lookup_u128(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u128) + lk);
		lk = _lookup_u128(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u128) + lk);
		*n -= sizeof(t_u128) * 2;
		*i += sizeof(t_u128) * 2;
	}
	while (*n >= sizeof(t_u128))
	{
		lk = _lookup_u128(*d++, x);
		if (lk != -1)
			return ((t_u8 *)d - sizeof(t_u128) + lk);
		*n -= sizeof(t_u128);
		*i += sizeof(t_u128);
	}
	return (NULL);
}
