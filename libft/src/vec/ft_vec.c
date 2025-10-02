/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	ft_vec(size_t alloc_size, size_t sizeof_type)
{
	t_vec	out;

	if (!alloc_size || !sizeof_type)
		return ((t_vec){0});
	if (SIZE_MAX / alloc_size <= sizeof_type)
		return ((t_vec){0});
	out.size = 0;
	out.alloc_size = alloc_size;
	out.data = ft_alloc(alloc_size * sizeof_type);
	if (!out.data)
		return ((t_vec){0});
	out.sizeof_type = sizeof_type;
	return (out);
}
