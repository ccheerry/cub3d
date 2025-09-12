/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"

void	*ft_extend_zero(void *ptr, size_t n, size_t size)
{
	unsigned char	*p2;

	if (size > SIZE_MAX - n || (size == 0 && ptr))
		return (ft_free(&ptr), NULL);
	if (!ptr)
		return (ft_calloc(n + size, 1));
	p2 = ft_calloc(n + size, 1);
	if (!p2)
		return (NULL);
	ft_memmove(p2, ptr, n);
	return (ft_free(&ptr), p2);
}
