/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr.h"

char	*ft_tstr_strrchr(const t_string *haystack, int needle)
{
	t_u8	*l_o;
	size_t	s;

	if (!haystack || !haystack->len || !haystack->alloc_size)
		return (NULL);
	l_o = NULL;
	s = haystack->len;
	if (needle == '\0')
		return ((char *)&(haystack->data[s]));
	while (s--)
		if (haystack->data[s] == (char)needle)
			return ((char *)&(haystack->data[s]));
	return ((char *)l_o);
}
