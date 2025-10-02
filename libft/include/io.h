/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file io.h
 * @brief Header file for input/output operations.
 *
 * This file contains declarations for functions that handle input/output
 * operations, including formatted printing, reading lines, and file handling.
 */

#ifndef IO_H
# define IO_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include "cstr.h"
# include "tstr.h"
# include "mem.h"
# include "alloc.h"

# ifndef EOF
#  define EOF -1
# endif

# ifndef BUFSIZE
#  define BUFSIZE 4096
# endif

/**
 * @brief Reads the next line from a file descriptor.
 *
 * This function reads characters from the specified file descriptor until
 * a newline character or the end of the file is encountered. The result is
 * returned as a dynamically allocated string.
 *
 * @param fd File descriptor to read from.
 * @return A dynamic string containing the line read, or an empty string on EOF.
 */
t_string		get_next_line(int fd);

/**
 * @brief Prints a character to a file descriptor.
 *
 * This function writes a single character to the specified file descriptor.
 *
 * @param c Character to print.
 * @param fd File descriptor to write to.
 * @return Number of characters written (always 1).
 */
int				ft_printchar_fd(const char c, int fd);

/**
 * @brief Prints a string to a file descriptor.
 *
 * This function writes a null-terminated string
 * to the specified file descriptor.
 *
 * @param s String to print.
 * @param fd File descriptor to write to.
 * @return Number of characters written.
 */
int				ft_printstr_fd(const char *s, int fd);

/**
 * @brief Prints an integer to a file descriptor.
 *
 * This function writes the string representation of an integer
 * to the specified
 * file descriptor. It also updates a counter for the number
 * of characters written.
 *
 * @param n Integer to print.
 * @param fd File descriptor to write to.
 * @param c Pointer to a counter for the number of characters written.
 */
void			ft_printnbr_fd(int n, int fd, int *c);

/**
 * @brief Prints an unsigned integer to a file descriptor.
 *
 * This function writes the string representation of an unsigned integer to the
 * specified file descriptor. It also updates a counter for the number
 * of characters written.
 *
 * @param n Unsigned integer to print.
 * @param fd File descriptor to write to.
 * @param c Pointer to a counter for the number of characters written.
 */
void			ft_printunbr_fd(unsigned int n, int fd, int *c);

/**
 * @brief Prints a pointer address to a file descriptor.
 *
 * This function writes the string representation of a pointer address to the
 * specified file descriptor. It also updates a counter for the number
 * of characters written.
 *
 * @param p Pointer to print.
 * @param c Pointer to a counter for the number of characters written.
 * @param fd File descriptor to write to.
 */
void			ft_printptr_fd(unsigned long p, int *c, int fd);

/**
 * @brief Prints a formatted string to the standard output.
 *
 * This function processes a format string and additional arguments to produce
 * a formatted output, which is written to the standard output.
 *
 * @param fmt Format string.
 * @param ... Additional arguments for formatting.
 * @return Number of characters written.
 */
int				ft_printf(const char *fmt, ...);

/**
 * @brief Prints a hexadecimal number to a file descriptor.
 *
 * This function writes the string representation of a hexadecimal number to
 * the specified file descriptor using the provided character set for digits.
 * It also updates a counter for the number of characters written.
 *
 * @param x Number to print.
 * @param set Character set for hexadecimal digits.
 * @param l Pointer to a counter for the number of characters written.
 * @param fd File descriptor to write to.
 */
void			ft_printhex_fd(unsigned int x, const char *set, int *l, int fd);

/**
 * @brief Prints a formatted string to a file descriptor.
 *
 * This function processes a format string and additional arguments to produce
 * a formatted output, which is written to the specified file descriptor.
 *
 * @param fd File descriptor to write to.
 * @param fmt Format string.
 * @param ... Additional arguments for formatting.
 * @return Number of characters written.
 */
int				ft_fprintf(int fd, const char *fmt, ...);

/**
 * @brief Reads a single character from a file descriptor.
 *
 * This function reads the next character from the specified file descriptor.
 * If the clean parameter is true, it cleans up internal buffers.
 *
 * @param fd File descriptor to read from.
 * @param clean If true, cleans up internal buffers.
 * @return The character read, or EOF on error or end of file.
 */
int				ft_fgetc(int fd, bool clean);

/**
 * @brief Reads a line from the standard input with an optional prompt.
 *
 * This function displays a prompt (if provided) and reads characters from
 * the standard input until a newline character or EOF is encountered. The
 * result is returned as a dynamically allocated string.
 *
 * @param prompt Prompt to display before reading.
 * @param clean If true, cleans up internal buffers.
 * @return A dynamic string containing the line read, or an empty string on EOF.
 */
t_string		ft_readline(t_string *prompt, bool clean);

#endif
