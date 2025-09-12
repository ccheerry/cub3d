/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mem.h
 * @brief Header file for memory manipulation functions.
 *
 * This file contains declarations for functions that perform various memory
 * operations such as copying, setting, swapping, and formatting.
 */

#ifndef MEM_H
# define MEM_H

# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include "alloc.h"
# include "structs.h"
# include "macros.h"

# define LONES_64 0x0101010101010101ULL
# define HIGHS_64 0x8080808080808080ULL
# define ZEROS_64 0x0000000000000000ULL
# define LONES_32  0x01010101U
# define HIGHS_32  0x80808080U
# define HASH_SEED 0xCCAAF344FDULL
# define HASH_PRIME 0xD0C76E161D9FULL

/**
 * @brief Sets a block of memory to zero.
 *
 * This function initializes a memory block by setting all its bytes to zero.
 * It is commonly used to clear memory before use.
 *
 * @param ptr Pointer to the memory block.
 * @param n Number of bytes to set to zero.
 */
void			ft_bzero(void *__restrict__ ptr, size_t n);

/**
 * @brief Fills a block of memory with a specified value.
 *
 * This function sets each byte in a memory block to a specified value.
 * It is useful for initializing or overwriting memory.
 *
 * @param s Pointer to the memory block.
 * @param c Value to set.
 * @param n Number of bytes to set.
 * @return Pointer to the memory block.
 */
void			*ft_memset(void *__restrict__ s, int c, size_t n);

/**
 * @brief Copies memory from source to destination.
 *
 * This function copies a specified number of bytes from a source memory
 * block to a destination memory block. The source and destination must
 * not overlap.
 *
 * @param dest Destination memory block.
 * @param src Source memory block.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory block.
 */
void			*ft_memcpy(void *__restrict__ dest,
					const void *__restrict__ src, size_t n);

/**
 * @brief Transfers memory from source to destination and zeroes the source.
 *
 * This function moves a specified number of bytes from a source memory
 * block to a destination memory block and sets the source memory to zero.
 *
 * @param dest Destination memory block.
 * @param src Source memory block.
 * @param n Number of bytes to transfer.
 */
void			ft_memtake(void *__restrict__ dest,
					void *__restrict__ src, size_t n);

/**
 * @brief Swaps memory between two blocks.
 *
 * This function exchanges the contents of two memory blocks of equal size.
 *
 * @param p1 First memory block.
 * @param p2 Second memory block.
 * @param n Number of bytes to swap.
 * @return 1 if successful, 0 otherwise.
 */
t_u8			ft_memswap(void *__restrict__ p1,
					void *__restrict__ p2, size_t n);

/**
 * @brief Swaps memory between two blocks using an external buffer.
 *
 * This function exchanges the contents of two memory blocks of equal size
 * using an external buffer to hold intermediate data.
 *
 * @param p1 First memory block.
 * @param p2 Second memory block.
 * @param n Number of bytes to swap.
 * @param buf External buffer for swapping.
 * @return 1 if successful, 0 otherwise.
 */
t_u8			ft_memswap_extern(void *__restrict__ p1,
					void *__restrict__ p2, size_t n,
					void *__restrict__ buf);

/**
 * @brief Moves memory from source to destination, handling overlap.
 *
 * This function copies a specified number of bytes from a source memory
 * block to a destination memory block, correctly handling overlapping
 * regions.
 *
 * @param dest Destination memory block.
 * @param src Source memory block.
 * @param n Number of bytes to move.
 * @return Pointer to the destination memory block.
 */
void			*ft_memmove(void *__restrict__ dest,
					const void *__restrict__ src, size_t n);

/**
 * @brief Searches for a byte in a memory block.
 *
 * This function scans a memory block for the first occurrence of a
 * specified byte value.
 *
 * @param ptr Memory block to search.
 * @param c Byte to search for.
 * @param n Number of bytes to search.
 * @return Pointer to the first occurrence of the byte, or NULL if not found.
 */
void			*ft_memchr(const void *__restrict__ ptr, int c, size_t n);

/**
 * @brief Compares two memory blocks.
 *
 * This function compares two memory blocks byte by byte and returns the
 * difference between the first differing bytes, or zero if they are equal.
 *
 * @param dest First memory block.
 * @param src Second memory block.
 * @param n Number of bytes to compare.
 * @return Difference between the first differing bytes, or 0 if equal.
 */
ssize_t			ft_memcmp(void *__restrict__ dest,
					const void *__restrict__ src, size_t n);

/**
 * @brief Clones a memory block.
 *
 * This function creates a duplicate of a memory block by allocating new
 * memory and copying the content of the original block.
 *
 * @param ptr Memory block to clone.
 * @param size Size of the memory block.
 * @return Pointer to the cloned memory block.
 */
void			*ft_memclone(void *__restrict__ ptr, size_t size);

/**
 * @brief Formats a memory block.
 *
 * This function applies a specific format to a memory block, typically
 * for alignment or initialization purposes.
 *
 * @param ptr Memory block to format.
 * @param size Size of the memory block.
 * @return Pointer to the formatted memory block.
 */
void			*ft_memformat(void *ptr, size_t size);

/**
 * @brief Broadcasts a memory pattern to a destination block.
 *
 * This function replicates a memory pattern from a source block to a
 * destination block multiple times.
 *
 * @param dst Destination memory block.
 * @param src Source memory block.
 * @param chunks Number of chunks to broadcast.
 * @param n Size of each chunk.
 */
void			ft_membroadcast(void *dst, void *src, size_t chunks, size_t n);

/*
 * COPY HELPERS
 * Functions to copy memory blocks in forward or backward directions.
 */
void			_copy_u8_fwd(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
void			_copy_u32_fwd(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
void			_copy_u64_fwd(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
void			_copy_u128_fwd(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
void			_copy_u8_bw(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
void			_copy_u32_bw(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
void			_copy_u64_bw(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
void			_copy_u128_bw(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);

/*
 * OVERWRITING HELPERS
 * Functions to overwrite memory blocks with specific values.
 */
void			_write_u8_fwd(void **__restrict__ dest,
					t_u8 x,
					size_t *__restrict__ n);
void			_write_u32_fwd(void **__restrict__ dest,
					t_u32 x,
					size_t *__restrict__ n);
void			_write_u64_fwd(void **__restrict__ dest,
					t_u64 x,
					size_t *__restrict__ n);
void			_write_u128_fwd(void **__restrict__ dest,
					t_u128 x,
					size_t *__restrict__ n);

/*
 * COMPARISON HELPERS
 * Functions to compare memory blocks.
 */
ssize_t			_cmp_u8(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
ssize_t			_cmp_u32(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
ssize_t			_cmp_u64(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);
ssize_t			_cmp_u128(void **__restrict__ dest,
					const void **__restrict__ src,
					size_t *__restrict__ n);

/*
 * LOOKUP HELPERS
 * Functions to perform lookups and checks on memory blocks.
 */
int				_lookup_u32(t_u32 word, t_u32 mask);
int				_lookup_u64(t_u64 word, t_u64 mask);
int				_lookup_u128(t_u128 word, t_u128 mask);
int				__hasz128(t_u128 x);
int				__hasz64(t_u64 x);
t_u128			__populate(t_u8 y);

/*
 * ALIGNMENT & ZERO CHECK HELPERS
 * Functions to check alignment and count trailing zeros in memory blocks.
 */
t_u8			ft_memctz_u32(t_u32 x);
t_u8			ft_memctz_u64(t_u64 x);
t_u8			ft_memctz_u128(t_u128 x);

/*
 * MAXIMUM VALUE HELPERS
 * Functions to compute the maximum of two values.
 */
size_t			__max_s(size_t x, size_t y);
t_u8			__maxu8(t_u8 x, t_u8 y);
t_u32			__maxu32(t_u32 x, t_u32 y);
t_u64			__maxu64(t_u64 x, t_u64 y);
t_u128			__maxu128(t_u128 x, t_u128 y);

/*
 *	HASHER
 */
t_u128			ft_hash(t_u8 *bytes, size_t n);
#endif
