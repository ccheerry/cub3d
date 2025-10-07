/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:58:55 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:58:55 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTR_H
# define CSTR_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "structs.h"
# include "alloc.h"
# include "mem.h"

size_t			ft_strlen(const char *str);
char			**ft_split(const char *str, char set);
int				ft_strcmp(const char *a, const char *b);

#endif
