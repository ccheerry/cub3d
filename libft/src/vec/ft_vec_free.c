/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:05 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:55:05 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	ft_vec_free(t_vec *v)
{
	if (!v)
		return ;
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->alloc_size = 0;
	v->sizeof_type = 0;
}
