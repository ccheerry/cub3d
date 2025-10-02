/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

t_string	get_next_line(int fd)
{
	char			c;
	static t_string	out;
	t_string		tmp;

	if (fd < 0)
		return ((t_string){0});
	if (!out.alloc_size)
	{
		out = ft_tstr_new(BUFSIZE);
		if (!out.data)
			return ((t_string){0});
	}
	c = ft_fgetc(fd, false);
	while (c != EOF && c != '\n')
	{
		ft_tstr_push(&out, c);
		c = ft_fgetc(fd, false);
	}
	if (c == '\n')
		ft_tstr_push(&out, c);
	if (c == EOF)
		return (ft_tstr_free(&out), (t_string){0});
	tmp = ft_tstr_clone(&out);
	return (ft_tstr_clear(&out), tmp);
}
