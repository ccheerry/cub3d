/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file tstr.h
 * @brief Header file for dynamic string operations.
 *
 * This file contains the declarations and documentation for functions
 * that operate on dynamic strings (t_string).
 */

#ifndef TSTR_H
# define TSTR_H

# include <sys/types.h>
# include <stdlib.h>
# include "structs.h"
# include "mem.h"
# include "alloc.h"
# include "cstr.h"

/**
 * @brief Creates a dynamic string from a C-string.
 *
 * This function initializes a new dynamic string using the content of a
 * null-terminated C-string. The resulting dynamic string can be modified
 * or resized as needed.
 *
 * @param str Input C-string.
 * @return A new dynamic string instance.
 */
t_string		ft_tstr_from_cstr(const char *str);

/**
 * @brief Duplicates a dynamic string into a C-string.
 *
 * This function creates a copy of the content of a dynamic string and
 * returns it as a newly allocated null-terminated C-string.
 *
 * @param str Input dynamic string.
 * @return A newly allocated C-string.
 */
char			*ft_tstr_dup_cstr(t_string *str);

/**
 * @brief Creates a new dynamic string with a specified initial length.
 *
 * This function allocates memory for a dynamic string with a given
 * initial length. The content of the string is uninitialized.
 *
 * @param len Initial length of the string.
 * @return A new dynamic string instance.
 */
t_string		ft_tstr_new(size_t len);

/**
 * @brief Appends a C-string to a dynamic string.
 *
 * This function concatenates a null-terminated C-string to the end of
 * a dynamic string, resizing it if necessary.
 *
 * @param str Target dynamic string.
 * @param s C-string to append.
 */
void			ft_tstr_pushstr(t_string *str, const char *s);

/**
 * @brief Appends a single character to a dynamic string.
 *
 * This function adds a single character to the end of a dynamic string,
 * resizing it if necessary.
 *
 * @param str Target dynamic string.
 * @param c Character to append.
 */
void			ft_tstr_push(t_string *str, char c);

/**
 * @brief Frees the memory allocated for a dynamic string.
 *
 * This function releases all memory associated with a dynamic string,
 * including its content and metadata.
 *
 * @param str Target dynamic string.
 */
void			ft_tstr_free(t_string *str);

/**
 * @brief Returns a constant pointer to the data of a dynamic string.
 *
 * This function provides read-only access to the content of a dynamic
 * string as a null-terminated C-string.
 *
 * @param str Target dynamic string.
 * @return Constant pointer to the string data.
 */
const char		*ft_tstr_borrow(const t_string *str);

/**
 * @brief Clears the contents of a dynamic string without deallocating memory.
 *
 * This function resets the length of a dynamic string to zero, effectively
 * clearing its content. The allocated memory remains intact for reuse.
 *
 * @param s Target dynamic string.
 */
void			ft_tstr_clear(t_string *s);

/**
 * @brief Shrinks the allocation size to fit its current length.
 *
 * This function reduces the allocated memory of a dynamic string to match
 * its current length, freeing any unused memory.
 *
 * @param str Target dynamic string.
 */
void			ft_tstr_fit(t_string *str);

/**
 * @brief Finds the first occurrence of a substring in a dynamic string.
 *
 * This function searches for the first occurrence of a null-terminated
 * substring within a dynamic string and returns its index.
 *
 * @param h Haystack dynamic string.
 * @param n Needle substring.
 * @return Index of the first occurrence, or -1 if not found.
 */
ssize_t			ft_tstr_instr(const t_string *h, const char *n);

/**
 * @brief Trims characters from the start and end of a dynamic string.
 *
 * This function removes all characters from the start and end of a dynamic
 * string that are present in the specified set.
 *
 * @param str Target dynamic string.
 * @param set Set of characters to trim.
 */
void			ft_tstr_trim(t_string *str, const char *set);
void			ft_tstr_trim_one(t_string *str, const char *set);
/**
 * @brief Creates a dynamic string from a slice of a C-string.
 *
 * This function initializes a new dynamic string using a specified portion
 * of a null-terminated C-string.
 *
 * @param s Input C-string.
 * @param n Length of the slice.
 * @return A new dynamic string instance.
 */
t_string		ft_tstr_from_slice(char *s, size_t n);

/**
 * @brief Appends a slice of a C-string to a dynamic string.
 *
 * This function concatenates a specified portion of a null-terminated
 * C-string to the end of a dynamic string, resizing it if necessary.
 *
 * @param str Target dynamic string.
 * @param s Input C-string.
 * @param n Length of the slice.
 */
void			ft_tstr_pushslice(t_string *str, const char *s, size_t n);

/**
 * @brief Ensures a dynamic string has at least 'n' additional allocation size.
 *
 * This function checks if a dynamic string has enough allocated memory to
 * accommodate 'n' additional characters. If not, it resizes the string.
 *
 * @param str Target dynamic string.
 * @param n Minimum additional allocation size.
 */
void			ft_tstr_reserve(t_string *str, size_t n);

/**
 * @brief Removes the last character from a dynamic string.
 *
 * This function decreases the length of a dynamic string by one and
 * returns the removed character.
 *
 * @param str Target dynamic string.
 * @return The removed character.
 */
char			ft_tstr_pop(t_string *str);

/**
 * @brief Repeats a chunk of a C-string and appends it to a dynamic string.
 *
 * This function concatenates a specified chunk of a null-terminated
 * C-string to a dynamic string multiple times.
 *
 * @param str Target dynamic string.
 * @param chunk C-string chunk to repeat.
 * @param times Number of repetitions.
 */
void			ft_tstr_repeat(t_string *str, const char *chunk, size_t times);

/**
 * @brief Creates a clone of a dynamic string.
 *
 * This function creates a new dynamic string with the same content as
 * the input dynamic string.
 *
 * @param s Input dynamic string.
 * @return A new dynamic string instance.
 */
t_string		ft_tstr_clone(t_string *s);

/**
 * @brief Finds the last occurrence of a character in a dynamic string.
 *
 * This function searches for the last occurrence of a character within
 * a dynamic string and returns a pointer to it.
 *
 * @param haystack Target dynamic string.
 * @param needle Character to find.
 * @return Pointer to the last occurrence, or NULL if not found.
 */
char			*ft_tstr_strrchr(const t_string *haystack, int needle);

void			ft_tstr_insert(t_string *str,
					char *topush, size_t s, size_t idx);

#endif
