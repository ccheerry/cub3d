/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:23:14 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	ft_vec_remove(t_vec *v, size_t i)
{
	if (!v || !v->size || !v->data || i >= v->size)
		return ;
	if (i == v->size - 1)
		ft_vec_pop(v);
	else
	{
		ft_memmove(ft_vec_get_mut(v, i),
			ft_vec_get_mut(v, i + 1), (v->size - i - 1) * v->sizeof_type);
		v->size--;
	}
}

void	ft_vec_remove_f(t_vec *v, size_t i, void (*f) (void *))
{
	void	*element;

	if (!v || !v->size || !v->data || i >= v->size)
		return ;
	element = ft_vec_get_mut(v, i);
	if (!element)
		return ;
	if (i == v->size - 1)
	{
		f(element);
		ft_vec_pop(v);
	}
	else
	{
		f(element);
		ft_memmove(ft_vec_get_mut(v, i),
			ft_vec_get_mut(v, i + 1), (v->size - i - 1) * v->sizeof_type);
		v->size--;
	}
}
