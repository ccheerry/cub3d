/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:47 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:55:47 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr.h"

t_string	ft_tstr_clone(t_string *s)
{
	t_string	new;

	if (!s || !s->alloc_size)
		return ((t_string){0});
	new.data = ft_memclone(s->data, s->alloc_size);
	new.len = s->len;
	new.alloc_size = s->alloc_size;
	return (new);
}
