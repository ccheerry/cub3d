/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:56:06 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:56:06 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_dst < ptr_src)
	{
		while (n--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_dst += n;
		ptr_src += n;
		while (n--)
			*--ptr_dst = *--ptr_src;
	}
	return (dest);
}
