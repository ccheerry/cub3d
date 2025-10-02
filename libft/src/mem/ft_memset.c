/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline void	*ft_memset(void *__restrict__ dest, int c, size_t n)
{
	t_u128	x;
	void	*ret;

	if ((!dest) && n != 0)
		return (NULL);
	x = __populate(c);
	ret = dest;
	_write_u128_fwd((void **)&dest, x, &n);
	_write_u64_fwd((void **)&dest, x, &n);
	_write_u32_fwd((void **)&dest, x, &n);
	_write_u8_fwd((void **)&dest, x, &n);
	return (ret);
}
