/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:38:18 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr.h"

void	ft_tstr_insert(t_string *str, char *topush, size_t s, size_t idx)
{
	if (!str || !topush || !s)
		return ;
	if (!str->data || !str->alloc_size || idx == str->len)
	{
		ft_tstr_pushslice(str, topush, s);
		return ;
	}
	if (idx > str->len)
		ft_tstr_repeat(str, " ", idx - str->len);
	if (str->alloc_size < str->len + s + 1)
		ft_tstr_reserve(str, s);
	if (idx < str->len)
		ft_memmove(str->data + idx + s, str->data + idx, str->len - idx - 1);
	ft_memcpy(str->data + idx, topush, s);
	str->len += s;
	str->data[str->len] = 0;
}
