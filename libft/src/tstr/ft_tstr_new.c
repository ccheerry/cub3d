/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:27 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:55:28 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

t_string	ft_tstr_new(size_t len)
{
	t_string	out;

	out.len = 0;
	out.alloc_size = (size_t) len + 1;
	out.data = ft_calloc(out.alloc_size, 1);
	if (!out.data)
		out = (t_string){0};
	return (out);
}
