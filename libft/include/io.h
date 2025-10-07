/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:58:50 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:58:50 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include "structs.h"
# include "tstr.h"

# ifndef BUFSIZE
#  define BUFSIZE 4096
# endif

void			ft_putstr_fd(const char *str, int fd);
t_string		get_next_line(int fd);
int				ft_fgetc(int fd, bool clean);

#endif
