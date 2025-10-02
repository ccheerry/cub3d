/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memchr(const void *__restrict__ ptr, int c, size_t n)
{
	unsigned int	i;
	t_u8			*p;

	p = (t_u8 *)ptr;
	i = 0;
	while (i < n)
	{
		if (p[i] == (t_u8)c)
			return (p + i);
		i++;
	}
	return ((void *) 0);
}
