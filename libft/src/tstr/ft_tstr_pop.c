/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr.h"

char	ft_tstr_pop(t_string *str)
{
	char	o;

	if (!str || !str->data || !str->len)
		return (0);
	o = ft_tstr_borrow(str)[str->len - 1];
	str->data[str->len - 1] = 0;
	str->len--;
	return (o);
}
