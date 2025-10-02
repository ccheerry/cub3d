/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline void	*ft_memmove(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	t_u8	*bd;
	t_u8	*bs;

	if ((!dest || !src || dest == src) && n != 0)
		return (NULL);
	if ((t_uptr)src < (t_uptr)dest
		&& (t_uptr)src + n >= (t_uptr)dest)
	{
		bd = (t_u8 *)dest + n;
		bs = (t_u8 *)src + n;
		_copy_u128_bw((void **)&bd, (const void **)&bs, &n);
		_copy_u64_bw((void **)&bd, (const void **)&bs, &n);
		_copy_u32_bw((void **)&bd, (const void **)&bs, &n);
		_copy_u8_bw((void **)&bd, (const void **)&bs, &n);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
