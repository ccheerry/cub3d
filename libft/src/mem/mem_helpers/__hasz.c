/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __hasz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE_HOT inline int	__hasz64(t_u64 x)
{
	return (((x) -LONES_64) & (~x) & HIGHS_64);
}

FT_INLINE_HOT inline int	__hasz128(t_u128 x)
{
	t_u64	low_part;
	t_u64	high_part;

	high_part = (t_u64)(x >> 64);
	low_part = (t_u64)x;
	return (__hasz64(low_part) || __hasz64(high_part));
}
