/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:59:05 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:59:05 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_H
# define ALLOC_H

# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include "mem.h"
# include "macros.h"
# include "structs.h"

# ifndef DEF_ALIGN
#  define DEF_ALIGN 128
# endif

void			*ft_alloc(size_t size);
void			ft_free(void **ptr);
void			ft_free_array(void ***arr);
void			*ft_calloc(size_t n, size_t size);
void			*ft_extend_zero(void *ptr, size_t n, size_t size);

#endif
