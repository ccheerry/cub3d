/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:58:09 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:59:23 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file structs.h
 * @brief Header file defining core data structures.
 *
 * This file contains the definitions of various data structures and typedefs
 * used throughout the library, including dynamic strings, vectors, and memory
 * arenas.
 */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <sys/types.h>
# include <stdint.h>
# include "macros.h"

/**
 * @struct t_string
 * @brief Represents a dynamic string.
 *
 * This structure is used to manage strings that can grow or shrink dynamically.
 * It provides metadata for efficient memory management and string operations.
 *
 * @var t_string::len
 * The current length of the string, excluding the null terminator.
 * @var t_string::alloc_size
 * The total allocated memory for the string + null terminator.
 * @var t_string::data
 * A pointer to the character array holding the string's content.
 */
typedef struct s_string
{
	size_t	len;
	size_t	alloc_size;
	char	*data;
}	t_string;

/**
 * @struct t_vec
 * @brief Represents a dynamic vector.
 *
 * This structure is used to manage a resizable array of elements. It provides
 * metadata for efficient memory management and supports elements of any type.
 *
 * @var t_vec::size
 * The number of elements currently stored in the vector.
 * @var t_vec::data
 * A pointer to the allocated memory holding the vector's elements.
 * @var t_vec::alloc_size
 * The total number of slots allocated for elements in the vector.
 * @var t_vec::sizeof_type
 * The size of each element in bytes, used for memory calculations.
 */
typedef struct s_vec
{
	size_t	size;
	void	*data;
	size_t	alloc_size;
	size_t	sizeof_type;
}	t_vec;

#endif
