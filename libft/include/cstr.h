/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTR_H
# define CSTR_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include "structs.h"
# include "ctype.h"
# include "alloc.h"
# include "mem.h"

int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strchr(const char *haystack, int needle);
char			*ft_strchr_small(const char *haystack, int needle);
char			*ft_strrchr(const char *haystack, int needle);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t n);
char			*ft_strtrim(const char *str, const char *set);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			**ft_split(const char *str, char set);
int				ft_strcmp(const char *a, const char *b);
t_u8			ft_isnumeric(const char *__restrict__ s);
bool			ft_s_isblob(char *s);
#endif
