/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
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
		new_alloc = __max_s(vec->alloc_size * 2, vec->size + len);
		tmp = ft_extend_zero(vec->data,
				vec->alloc_size * vec->sizeof_type,
				(new_alloc - vec->alloc_size) * vec->sizeof_type);
		if (!tmp)
			return ;
		vec->data = tmp;
		vec->alloc_size = new_alloc;
	}
	ft_memcpy(((t_u8 *)(vec->data) + (vec->size * vec->sizeof_type)),
		data, len * vec->sizeof_type);
	vec->size += len;
}
