/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:37 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:55:37 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

void	ft_tstr_free(t_string *str)
{
	if (str->data)
	{
		free(str->data);
		str->data = NULL;
	}
	str->len = 0;
	str->alloc_size = 0;
}
