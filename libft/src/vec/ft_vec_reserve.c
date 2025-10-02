/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	ft_vec_reserve(t_vec *v, size_t n)
{
	void	*new;

	if (!v || !n || n <= v->alloc_size)
		return ;
	new = ft_extend_zero(v->data, v->alloc_size * v->sizeof_type,
			n * v->sizeof_type);
	if (!new)
		return ;
	v->data = new;
	v->alloc_size += n;
}
