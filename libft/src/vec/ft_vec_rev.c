/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	ft_vec_rev(t_vec *v)
{
	size_t	half;
	size_t	i;

	if (!v || v->size < 2)
		return ;
	half = v->size / 2;
	i = 0;
	while (i < half)
	{
		ft_memswap(
			(t_u8 *)v->data + (v->sizeof_type * i),
			(t_u8 *)v->data + (v->sizeof_type * (v->size - i - 1)),
			v->sizeof_type);
		i++;
	}
}
