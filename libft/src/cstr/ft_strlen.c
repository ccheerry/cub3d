/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

size_t	ft_strlen(const char *str)
{
	const char	*a;
	ssize_t		lk;
	const t_u64	*w_64;

	if (!str)
		return (0);
	a = str;
	while ((t_uptr)str % sizeof(t_u64))
	{
		if (*str == '\0')
			return (str - a);
		str++;
	}
	w_64 = (const t_u64 *)str;
	while (1)
	{
		lk = _lookup_u64(w_64[0], __populate(0));
		if (lk != -1)
		{
			str = (const char *)w_64 + lk;
			break ;
		}
		w_64++;
	}
	return (str - a);
}
