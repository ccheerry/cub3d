/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:57:17 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:57:17 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"

void	ft_free(void **ptr)
{
	void	*pp;

	if (!ptr || !*ptr)
		return ;
	pp = *ptr;
	free(((void **)pp)[-1]);
	*ptr = NULL;
}

void	ft_free_array(void ***arr)
{
	size_t	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
		ft_free(&((*arr)[i++]));
	ft_free((void **)arr);
}
