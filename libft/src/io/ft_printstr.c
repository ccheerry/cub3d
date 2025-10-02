/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

int	ft_printstr_fd(const char *str, int fd)
{
	unsigned int	l;

	if (!str)
	{
		return (write(fd, "(null)", 6));
	}
	l = 0;
	while (str[l])
		l += write (fd, str + l, 1);
	return ((int) l);
}
