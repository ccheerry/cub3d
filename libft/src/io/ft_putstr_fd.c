/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:56:31 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:56:31 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		write(fd, &(str[i++]), 1);
}
