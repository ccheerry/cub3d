/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_H
# define ALLOC_H

/**
 * @file alloc.h
 * @brief Header file for memory allocation utilities.
 *
 * Contains declarations for custom memory allocation, deallocation,
 * and management functions.
 */

# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include <stdarg.h>
# include "mem.h"
# include "macros.h"
# include "structs.h"

/**
 * @def DEF_ALIGN
 * @brief Default alignment size for memory allocations.
 */
# ifndef DEF_ALIGN
#  define DEF_ALIGN 128
# endif

/**
 * @def DEFAULT_ARENA_SIZE
 * @brief Default size for memory arenas.
 */
# ifndef DEFAULT_ARENA_SIZE
#  define DEFAULT_ARENA_SIZE 262272
# endif

/**
 * @brief Allocates memory of the specified size.
 *
 * Allocates a block of memory of the given size and returns a pointer to it.
 * The contents of the memory are uninitialized.
 *
 * @param size Size of memory to allocate.
 * @return Pointer to the allocated memory.
 */
void			*ft_alloc(size_t size);

/**
 * @brief Frees the memory pointed to by the given pointer.
 *
 * Releases the memory allocated at the address pointed to by the given pointer
 * and sets the pointer to NULL to prevent dangling pointers.
 *
 * @param ptr Pointer to the memory to free.
 */
void			ft_free(void **ptr);

/**
 * @brief Frees a 2D array of pointers.
 *
 * Releases the memory allocated for a 2D array of pointers and sets the array
 * pointer to NULL.
 *
 * @param arr Pointer to the array to free.
 */
void			ft_free_array(void ***arr);

/**
 * @brief Defers the freeing of a pointer.
 *
 * Schedules the memory pointed to by the given pointer to be freed at a later
 * time, typically at the end of the program or a specific scope.
 *
 * @param ptr Pointer to defer freeing.
 */
void			ft_defer(void *ptr);

/**
 * @brief Defers the freeing of a 2D array of pointers.
 *
 * Schedules the memory allocated for a 2D array of pointers to be freed at a
 * later time.
 *
 * @param ptr Pointer to the array to defer freeing.
 */
void			ft_defer_arr(void ***ptr);

/**
 * @brief Allocates and zeroes memory for an array.
 *
 * Allocates memory for an array of `n` elements, each of size `size`, and
 * initializes all bytes in the allocated memory to zero.
 *
 * @param n Number of elements.
 * @param size Size of each element.
 * @return Pointer to the allocated memory.
 */
void			*ft_calloc(size_t n, size_t size);

/**
 * @brief Extends the memory block by a specified size.
 *
 * Reallocates the memory block pointed to by `ptr` to a new size, extending it
 * by `size` bytes. The contents of the newly allocated memory are uninitialized.
 *
 * @param ptr Pointer to the existing memory block.
 * @param n Current size of the memory block.
 * @param size Size to extend by.
 * @return Pointer to the extended memory block.
 */
void			*ft_extend(void *ptr, size_t n, size_t size);

/**
 * @brief Extends the memory block by a specified size and zeroes the new memory.
 *
 * Reallocates the memory block pointed to by `ptr` to a new size, extending it
 * by `size` bytes. The newly allocated memory is initialized to zero.
 *
 * @param ptr Pointer to the existing memory block.
 * @param n Current size of the memory block.
 * @param size Size to extend by.
 * @return Pointer to the extended memory block.
 */
void			*ft_extend_zero(void *ptr, size_t n, size_t size);

/**
 * @brief Reallocates memory for a block with a new size.
 *
 * Changes the size of the memory block pointed to by `ptr` to `size` bytes.
 * The contents of the memory block are preserved up to the lesser of the new
 * and old sizes.
 *
 * @param ptr Pointer to the existing memory block.
 * @param n Current size of the memory block.
 * @param size New size of the memory block.
 * @return Pointer to the reallocated memory block.
 */
void			*ft_realloc(void *ptr, size_t n, size_t size);

/**
 * @brief Reallocates and zeroes memory for a block with a new size.
 *
 * Changes the size of the memory block pointed to by `ptr` to `size` bytes.
 * The newly allocated memory is initialized to zero.
 *
 * @param ptr Pointer to the existing memory block.
 * @param n Current size of the memory block.
 * @param size New size of the memory block.
 * @return Pointer to the reallocated memory block.
 */
void			*ft_recalloc(void *ptr, size_t n, size_t size);

/**
 * @brief Allocates memory from a memory arena.
 *
 * Allocates a block of memory from a pre-allocated memory arena. Memory
 * allocated from the arena is managed separately from the standard heap.
 *
 * @param size Size of memory to allocate.
 * @return Pointer to the allocated memory.
 */
void			*ft_arena(size_t size);

/**
 * @brief Frees all memory allocated in a memory arena.
 *
 * Releases all memory blocks allocated from the specified memory arena.
 *
 * @param arena Pointer to the memory arena to free.
 */
void			ft_free_arena(t_arena *arena);

#endif
