/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:57:58 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:57:58 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "structs.h"
# include "alloc.h"
# include <stddef.h>

t_vec		ft_vec(size_t alloc_size, size_t sizeof_type);
void		ft_vec_push(t_vec *vec, void *data, size_t len);
void		ft_vec_free(t_vec *vec);
void		*ft_vec_get_mut(t_vec *vec, size_t idx);
void		*ft_vec_get_clone(t_vec *vec, size_t idx);
const void	*ft_vec_get(t_vec *vec, size_t idx);

#endif
