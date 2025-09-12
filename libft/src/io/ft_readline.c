/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

t_string	ft_readline(t_string *prompt, bool clean)
{
	t_string	out;
	char		c;

	if (clean)
		return ((void)ft_fgetc(0, true), (t_string){0});
	out = ft_tstr_new(100);
	write(1, prompt->data, prompt->len);
	c = ft_fgetc(0, false);
	while (c != EOF && c != '\n')
	{
		ft_tstr_push(&out, c);
		c = ft_fgetc(0, false);
	}
	if (!out.len && out.alloc_size && c == EOF)
		return (ft_tstr_free(&out), (t_string){0});
	return (out);
}
