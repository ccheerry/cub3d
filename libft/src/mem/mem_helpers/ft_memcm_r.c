/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcm_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline ssize_t	_cmp_u8(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u8	*wd;
	t_u8	*ws;

	wd = (t_u8 *)*dest;
	ws = (t_u8 *)*src;
	while (*n >= sizeof(t_u8) * 2)
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u8) * 2;
	}
	while (*n >= sizeof(t_u8))
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u8);
	}
	*dest = wd;
	*src = ws;
	return (0);
}

inline ssize_t	_cmp_u32(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u32	*wd;
	t_u32	*ws;

	wd = (t_u32 *)*dest;
	ws = (t_u32 *)*src;
	while (*n >= sizeof(t_u32) * 2)
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u32) * 2;
	}
	while (*n >= sizeof(t_u32))
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u32);
	}
	*dest = wd;
	*src = ws;
	return (0);
}

inline ssize_t	_cmp_u64(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u64	*wd;
	t_u64	*ws;

	wd = (t_u64 *)*dest;
	ws = (t_u64 *)*src;
	while (*n >= sizeof(t_u64) * 2)
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u64) * 2;
	}
	while (*n >= sizeof(t_u64))
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u64);
	}
	*dest = wd;
	*src = ws;
	return (0);
}

inline ssize_t	_cmp_u128(void **__restrict__ dest,
	const void **__restrict__ src,
	size_t *__restrict__ n)
{
	t_u128	*wd;
	t_u128	*ws;

	wd = (t_u128 *)*dest;
	ws = (t_u128 *)*src;
	while (*n >= sizeof(t_u128) * 2)
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u128) * 2;
	}
	while (*n >= sizeof(t_u128))
	{
		if (*wd++ != *ws++)
			return (wd[-1] - ws[-1]);
		*n -= sizeof(t_u128);
	}
	*dest = wd;
	*src = ws;
	return (0);
}
