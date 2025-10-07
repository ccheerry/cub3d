/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:56:18 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:56:18 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memclone(void *ptr, size_t size)
{
	void	*new_reg;

	if (!ptr || size == 0)
		return (NULL);
	new_reg = malloc(size);
	if (!new_reg)
		return (NULL);
	ft_memmove(new_reg, ptr, size);
	return (new_reg);
}
