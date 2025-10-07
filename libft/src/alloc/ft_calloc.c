/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:57:26 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:57:27 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"

void	*ft_calloc(size_t n, size_t size)
{
	void			*alloc;
	size_t			total;

	total = n * size;
	if (size != 0 && n > SIZE_MAX / size)
		return (0);
	alloc = malloc(total);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, total);
	return (alloc);
}
