/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

inline void	ft_vec_pop(t_vec *__restrict__ v)
{
	void	*ptr;

	if (!v || !v->data || v->size == 0)
		return ;
	v->size--;
	ptr = (t_u8 *)v->data + (v->size * v->sizeof_type);
	ft_bzero(ptr, v->sizeof_type);
}
