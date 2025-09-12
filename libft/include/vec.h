/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:00 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file vec.h
 * @brief Header file for dynamic vector operations.
 *
 * This file contains the declarations and documentation for functions
 * that operate on dynamic vectors (t_vec).
 */

#ifndef VEC_H
# define VEC_H

# include "macros.h"
# include "mem.h"
# include "structs.h"
# include <stddef.h>

/**
 * @brief Creates a vector with specified allocation size and type size.
 *
 * This function initializes a dynamic vector with a given initial allocation
 * size and the size of each element. It allocates memory for the vector and
 * sets its metadata accordingly.
 *
 * @param alloc_size Initial allocation size.
 * @param sizeof_type Size of each element in bytes.
 * @return A new vector instance with the specified properties.
 */
t_vec		ft_vec(size_t alloc_size, size_t sizeof_type);

/**
 * @brief Appends data to the vector, resizing if necessary.
 *
 * This function adds new elements to the end of the vector. If the vector's
 * allocated memory is insufficient, it automatically resizes to accommodate
 * the new elements.
 *
 * @param vec Target vector to which data will be appended.
 * @param data Pointer to the data to append.
 * @param len Number of elements to append.
 */
void		ft_vec_push(t_vec *vec, void *data, size_t len);

/**
 * @brief Frees the memory allocated for the vector.
 *
 * This function releases all memory associated with the vector, including
 * its elements and metadata. The vector should not be used after calling
 * this function.
 *
 * @param vec Target vector to free.
 */
void		ft_vec_free(t_vec *vec);

/**
 * @brief Ensures the vector has at least 'n' allocation size.
 *
 * This function checks if the vector's allocated memory can hold at least
 * 'n' elements. If not, it resizes the vector to meet the requirement.
 *
 * @param v Target vector to reserve memory for.
 * @param n Minimum allocation size in terms of number of elements.
 */
void		ft_vec_reserve(t_vec *v, size_t n);

/**
 * @brief Removes the last element from the vector.
 *
 * This function decreases the size of the vector by one, effectively removing
 * the last element. The memory for the removed element is not deallocated.
 *
 * @param v Target vector from which the last element will be removed.
 */
void		ft_vec_pop(t_vec *__restrict__ v);

/**
 * @brief Clears the vector's contents without deallocating memory.
 *
 * This function resets the vector's size to zero, effectively clearing its
 * contents. The allocated memory remains intact for future use.
 *
 * @param vec Target vector to clear.
 */
void		ft_vec_clear(t_vec *vec);

/**
 * @brief Shrinks the vector's allocation size to fit its current size.
 *
 * This function reduces the vector's allocated memory to match its current
 * size, freeing any unused memory.
 *
 * @param vec Target vector to shrink.
 */
void		ft_vec_fit(t_vec *vec);

/**
 * @brief Inserts data at a specific index in the vector.
 *
 * This function adds new elements to the vector at the specified index,
 * shifting existing elements to make room. If necessary, the vector is
 * resized to accommodate the new elements.
 *
 * @param v Target vector where data will be inserted.
 * @param index Position in the vector to insert the data.
 * @param data Pointer to the data to insert.
 * @param len Number of elements to insert.
 */
void		ft_vec_insert(t_vec *v, size_t index, void *data, size_t len);

/**
 * @brief Returns a pointer to the last element in the vector.
 *
 * This function provides direct access to the last element in the vector.
 * It does not modify the vector's contents or metadata.
 *
 * @param v Target vector to retrieve the last element from.
 * @return Pointer to the last element in the vector.
 */
void		*ft_vec_peek_last(t_vec *__restrict__ v);

/**
 * @brief Moves the last element of the vector to the destination and removes it.
 *
 * This function copies the last element of the vector to a specified destination
 * buffer and then removes it from the vector. The vector's size is decreases.
 *
 * @param dst Pointer to the destination buffer.
 * @param v Target vector from which the last element will be moved.
 * @return 1 if the operation is successful, 0 otherwise.
 */
t_u8		ft_vec_popmv(void *__restrict__ dst, t_vec *__restrict__ v);

/**
 * @brief Reverses the order of elements in the vector.
 *
 * This function rearranges the elements in the vector so that their order
 * is reversed. The operation is performed in-place.
 *
 * @param v Target vector to reverse.
 */
void		ft_vec_rev(t_vec *v);

/**
 * @brief Returns a mutable pointer to the element at the specified index.
 *
 * This function provides direct access to an element in the vector at the
 * given index. The returned pointer can be used to modify the element.
 *
 * @param vec Target vector to retrieve the element from.
 * @param idx Index of the element to access.
 * @return Mutable pointer to the element at the specified index.
 */
void		*ft_vec_get_mut(t_vec *vec, size_t idx);

/**
 * @brief Returns a clone of the element at the specified index.
 *
 * This function creates a copy of the element at the given index in the
 * vector and returns a pointer to the cloned element.
 *
 * @param vec Target vector to retrieve the element from.
 * @param idx Index of the element to clone.
 * @return Pointer to the cloned element.
 */
void		*ft_vec_get_clone(t_vec *vec, size_t idx);

/**
 * @brief Returns a constant pointer to the element at the specified index.
 *
 * This function provides read-only access to an element in the vector at
 * the given index. The returned pointer cannot be used to modify the element.
 *
 * @param vec Target vector to retrieve the element from.
 * @param idx Index of the element to access.
 * @return Constant pointer to the element at the specified index.
 */
const void	*ft_vec_get(t_vec *vec, size_t idx);

void		ft_vec_remove_f(t_vec *v, size_t i, void (*f) (void *));
void		ft_vec_remove(t_vec *v, size_t i);

#endif
