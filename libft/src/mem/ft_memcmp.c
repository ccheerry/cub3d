/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

ssize_t	ft_memcmp(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	ssize_t	r3;

	if ((!dest && !src) || n == 0 || dest == src)
		return (0);
	if ((!dest && src) || (!src && dest))
		return (-1);
	r3 = _cmp_u128((void **)&dest, (const void **)&src, &n);
	if (n && !r3)
		r3 = _cmp_u64((void **)&dest, (const void **)&src, &n);
	if (n && !r3)
		r3 = _cmp_u32((void **)&dest, (const void **)&src, &n);
	if (n && !r3)
		r3 = _cmp_u8((void **)&dest, (const void **)&src, &n);
	return (r3);
}
