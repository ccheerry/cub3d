/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_repeat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr.h"

void	ft_tstr_repeat(t_string *str, const char *chunk, size_t times)
{
	size_t	chunk_len;
	size_t	total_len;
	char	*new_data;
	size_t	i;

	if (!str || !chunk || !times)
		return ;
	chunk_len = ft_strlen(chunk);
	total_len = chunk_len * times;
	if ((total_len / times) != chunk_len)
		return ;
	if (str->len + total_len + 1 > str->alloc_size)
	{
		new_data = ft_extend_zero(str->data, str->alloc_size,
				str->len + total_len + 1);
		if (!new_data)
			return ;
		str->data = new_data;
		str->alloc_size = str->len + total_len + 1;
	}
	i = 0;
	while (i < times)
		ft_memcpy(str->data + str->len + i++ *chunk_len, chunk, chunk_len);
	str->len += total_len;
	str->data[str->len] = 0;
}
