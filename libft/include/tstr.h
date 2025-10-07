/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:58:03 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:58:03 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSTR_H
# define TSTR_H

# include <sys/types.h>
# include <stdlib.h>
# include "structs.h"
# include "mem.h"
# include "alloc.h"

t_string		ft_tstr_from_cstr(const char *str);
void			ft_tstr_free(t_string *str);
t_string		ft_tstr_clone(t_string *s);
void			ft_tstr_clear(t_string *s);
void			ft_tstr_push(t_string *str, char c);
t_string		ft_tstr_new(size_t len);

#endif
