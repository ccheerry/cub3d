/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	ft_vec_insert(t_vec *v, size_t index, void *data, size_t len)
{
	void	*new;
	size_t	new_alloc;

	if (!v || !data || len == 0 || index > v->size)
		return ;
	if (v->alloc_size < v->size + len)
	{
		new_alloc = __max_s(v->alloc_size * 2, v->size + len);
		new = ft_extend_zero(v->data, v->alloc_size * v->sizeof_type,
				(new_alloc - v->alloc_size) * v->sizeof_type);
		if (!new)
			return ;
		v->data = new;
		v->alloc_size = new_alloc;
	}
	ft_memmove((t_u8 *)v->data + (index + len) * v->sizeof_type,
		(t_u8 *)v->data + index * v->sizeof_type,
		(v->size - index) * v->sizeof_type);
	ft_memcpy((t_u8 *)v->data + index * v->sizeof_type,
		data, len * v->sizeof_type);
	v->size += len;
}
