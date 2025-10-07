/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:58:30 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:58:35 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <sys/types.h>
# include <stdlib.h>
# include "structs.h"

void			*ft_alloc(size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest,
					const void *src, size_t n);
void			*ft_memmove(void *dest,
					const void *src, size_t n);
void			*ft_memclone(void *ptr, size_t size);

#endif
