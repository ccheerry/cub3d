/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_fit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr.h"

void	ft_tstr_fit(t_string *str)
{
	char	*new;

	if (!str || str->len + 1 == str->alloc_size)
		return ;
	new = ft_realloc(str->data, str->alloc_size, str->len + 1);
	if (!new)
		return ;
	str->data = new;
	str->alloc_size = str->len + 1;
}
