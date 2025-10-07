/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:19 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:55:20 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

void	ft_tstr_push(t_string *str, char c)
{
	if (!str)
		return ;
	if (str->len + 1 < str->alloc_size)
	{
		str->data[str->len++] = c;
		str->data[str->len] = 0;
		return ;
	}
	str->data = ft_extend_zero(str->data, str->alloc_size, str->alloc_size * 2);
	str->alloc_size *= 2;
	if (!str->data)
		return ;
	str->data[str->len++] = c;
	str->data[str->len] = 0;
}
