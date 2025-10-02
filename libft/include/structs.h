/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:59 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
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
 * @typedef t_u8
 * @brief Alias for an unsigned 8-bit integer.
 *
 * This type is used to represent a single byte of data, often for raw memory
 * manipulation or binary data processing.
 */
typedef unsigned char __attribute__((__may_alias__))	t_u8;

/**
 * @typedef t_u32
 * @brief Alias for an unsigned 32-bit integer.
 *
 * This type is commonly used for representing medium-sized numerical values,
 * such as IDs, counters, or indices, where 32 bits of precision are sufficient.
 */
typedef uint32_t __attribute__((__may_alias__))			t_u32;

/**
 * @typedef t_u64
 * @brief Alias for an unsigned 64-bit integer.
 *
 * This type is suitable for large numerical values, such as timestamps,
 * file sizes, or other data requiring 64 bits of precision.
 */
typedef uint64_t __attribute__((__may_alias__))			t_u64;

/**
 * @typedef t_u128
 * @brief Alias for an unsigned 128-bit integer.
 *
 * This type is used for extremely large numerical values, such as cryptographic
 * keys or high-precision calculations, where 128 bits of precision are required.
 */
typedef __uint128_t __attribute__((__may_alias__))		t_u128;

/**
 * @typedef t_uptr
 * @brief Alias for an unsigned pointer-sized integer.
 *
 * This type is used to store memory addresses or perform pointer arithmetic
 * in a platform-independent manner, ensuring compatibility with the system's
 * pointer size.
 */
typedef uintptr_t __attribute__((__may_alias__))		t_uptr;

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

/**
 * @struct t_arena
 * @brief Represents a memory arena for efficient memory allocation.
 *
 * @var t_arena::size
 * Total size of the memory pool.
 * @var t_arena::offset
 * Current offset within the memory pool.
 * @var t_arena::next
 * Pointer to the next memory arena in the chain.
 * @var t_arena::pool
 * Pointer to the memory pool.
 */
typedef struct s_arena
{
	size_t			size;
	size_t			offset;
	struct s_arena	*next;
	void			*pool;
}	t_arena;

#endif
