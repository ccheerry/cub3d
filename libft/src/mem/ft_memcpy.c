/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline void	*ft_memcpy(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	void	*ret;

	if ((!dest || !src || dest == src) && n != 0)
		return (NULL);
	ret = dest;
	_copy_u128_fwd((void **)&dest, (const void **)&src, &n);
	_copy_u64_fwd((void **)&dest, (const void **)&src, &n);
	_copy_u32_fwd((void **)&dest, (const void **)&src, &n);
	_copy_u8_fwd((void **)&dest, (const void **)&src, &n);
	return (ret);
}
