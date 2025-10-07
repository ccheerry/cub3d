/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:54:55 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:54:56 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	ft_vec_push(t_vec *vec, void *data, size_t len)
{
	void	*tmp;
	size_t	new_alloc;

	if (!vec || !data)
		return ;
	if (vec->size + len > vec->alloc_size)
	{
		if (vec->alloc_size * 2 > vec->size + len)
			new_alloc = vec->alloc_size * 2;
		else
			new_alloc = vec->size + len;
		tmp = ft_extend_zero(vec->data,
				vec->alloc_size * vec->sizeof_type,
				(new_alloc - vec->alloc_size) * vec->sizeof_type);
		if (!tmp)
			return ;
		vec->data = tmp;
		vec->alloc_size = new_alloc;
	}
	ft_memcpy(((uint8_t *)(vec->data) + (vec->size * vec->sizeof_type)),
		data, len * vec->sizeof_type);
	vec->size += len;
}
