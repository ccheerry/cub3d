/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif

FT_INLINE inline static t_u8	ft_memswap_dyn(void *__restrict__ p1,
	void *__restrict__ p2, size_t len)
{
	void	*buffer;

	if (!p1 || !p2 || !len)
		return (0);
	buffer = ft_alloc(len * sizeof(t_u8));
	if (!buffer)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	ft_free(&buffer);
	return (1);
}

FT_INLINE inline static t_u8	ft_memswap_bounded(void *__restrict__ p1,
	void *__restrict__ p2, size_t len)
{
	t_u8	buffer[BUFFER_SIZE];

	if (!p1 || !p2 || !len)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	return (1);
}

t_u8	ft_memswap(void *__restrict__ p1,
	void *__restrict__ p2, size_t len)
{
	if (len <= BUFFER_SIZE)
		return (ft_memswap_bounded(p1, p2, len));
	else
		return (ft_memswap_dyn(p1, p2, len));
}

FT_INLINE inline t_u8	ft_memswap_extern(void *__restrict__ p1,
	void *__restrict__ p2, size_t len,
	void *__restrict__ buffer)
{
	if (!p1 || !p2 || !len)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	return (1);
}
