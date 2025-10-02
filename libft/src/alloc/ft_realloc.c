/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"

void	*ft_realloc(void *ptr, size_t n, size_t size)
{
	void	*p;

	if (!size)
		return (ft_free(&ptr), NULL);
	if (!ptr)
		return (ft_alloc(size));
	p = ft_alloc(size);
	if (!p)
		return (ft_free(&ptr), NULL);
	if (size < n)
		n = size;
	ft_memmove(p, ptr, n);
	if (ptr)
		ft_free(&ptr);
	return (p);
}
