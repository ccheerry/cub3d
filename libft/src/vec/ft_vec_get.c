/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:00 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:55:01 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

const void	*ft_vec_get(t_vec *vec, size_t idx)
{
	uint8_t	*raw;

	if (!vec || !vec->size || idx > vec->size)
		return (NULL);
	raw = (uint8_t *)vec->data;
	return (raw + (vec->sizeof_type * idx));
}

void	*ft_vec_get_mut(t_vec *vec, size_t idx)
{
	uint8_t	*raw;

	if (!vec || !vec->size || idx > vec->size)
		return (NULL);
	raw = (uint8_t *)vec->data;
	return (raw + (vec->sizeof_type * idx));
}

void	*ft_vec_get_clone(t_vec *vec, size_t idx)
{
	uint8_t	*raw;

	if (!vec || !vec->size || idx > vec->size)
		return (NULL);
	raw = (uint8_t *)vec->data;
	return (ft_memclone(raw + (vec->sizeof_type * idx),
			vec->sizeof_type));
}
