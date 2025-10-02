/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	l;

	if (!needle || !*needle)
		return ((char *)haystack);
	if (!haystack || !*haystack)
		return (NULL);
	i = 0;
	l = ft_strlen(needle);
	if (l > n)
		return (NULL);
	while (haystack[i] && (i + l) <= n)
	{
		if (!ft_strncmp(&(haystack[i]), needle, l))
			return ((char *)(&(haystack[i])));
		i++;
	}
	return ((void *) 0);
}
