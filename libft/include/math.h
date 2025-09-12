/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file math.h
 * @brief Header file for mathematical operations.
 *
 * This file contains declarations for various mathematical functions,
 * including power, square root, rounding, and absolute value operations.
 */

#ifndef MATH_H
# define MATH_H

# include "mem.h"

/**
 * @union u_fp
 * @brief Union for floating-point manipulation.
 *
 * This union allows access to the binary representation of a double-precision
 * floating-point number as a 64-bit integer.
 *
 * @var u_fp::f
 * The floating-point value.
 * @var u_fp::i
 * The 64-bit integer representation of the floating-point value.
 */
typedef union u_fp
{
	double	f;
	t_u64	i;
}	t_fp;

/**
 * @brief Computes the fast square root of a number.
 *
 * This function calculates an approximation of the square root
 * using the "Quake III Arena" algorithm.
 *
 * @param x Input number.
 * @return Approximation of the square root.
 */
float			ft_q_sqrt(float x);

/**
 * @brief Computes the fast square root and rounds the result.
 *
 * This function calculates an approximation of the square root
 * and rounds the result to a specified number of decimal places.
 *
 * @param number Input number.
 * @param n Number of decimal places to round to.
 * @return Rounded approximation of the square root.
 */
float			ft_q_sqrt_round(float number, t_u8 n);

/**
 * @brief Computes the fast square root and rounds
 * to the nearest integer.
 *
 * This function calculates an approximation of the square root
 * and rounds the result to the nearest integer.
 *
 * @param number Input number.
 * @return Rounded approximation of the square root.
 */
float			ft_q_sqrt_fround(float number);

/**
 * @brief Rounds a floating-point number to a specified number of decimal places.
 *
 * This function rounds a floating-point number to the nearest value with
 * the specified number of decimal places.
 *
 * @param x Input number.
 * @param n Number of decimal places to round to.
 * @return Rounded number.
 */
float			ft_roundf(float x, t_u8 n);

/**
 * @brief Computes the largest integer less than or equal
 * to a floating-point number.
 *
 * This function calculates the floor of a floating-point number.
 *
 * @param x Input number.
 * @return Floor of the input number.
 */
float			ft_floorf(float x);

/**
 * @brief Computes the smallest integer greater than or equal
 * to a floating-point number.
 *
 * This function calculates the ceiling of a floating-point number.
 *
 * @param x Input number.
 * @return Ceiling of the input number.
 */
float			ft_ceilf(float x);

/**
 * @brief Computes the power of an unsigned 128-bit integer.
 *
 * This function raises an unsigned 128-bit integer to the power of another.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
t_u128			ft_pow_u128(t_u128 x, t_u128 n);

/**
 * @brief Computes the power of an unsigned 64-bit integer.
 *
 * This function raises an unsigned 64-bit integer to the power of another.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
t_u64			ft_pow_u64(t_u64 x, t_u64 n);

/**
 * @brief Computes the power of an unsigned 32-bit integer.
 *
 * This function raises an unsigned 32-bit integer to the power of another.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
t_u32			ft_pow_u32(t_u32 x, t_u32 n);

/**
 * @brief Computes the power of an unsigned 8-bit integer.
 *
 * This function raises an unsigned 8-bit integer to the power of another.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
t_u8			ft_pow_u8(t_u8 x, t_u8 n);

/**
 * @brief Computes the power of a signed integer.
 *
 * This function raises a signed integer to the power of an unsigned integer.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
int				ft_ipow(int x, t_u64 n);

/**
 * @brief Computes the power of a signed long long integer.
 *
 * This function raises a signed long long integer to the power
 * of an unsigned integer.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
long long		ft_lpow(long long x, t_u64 n);

/**
 * @brief Computes the power of a floating-point number.
 *
 * This function raises a floating-point number to
 * the power of an unsigned integer.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
float			ft_fpow(float x, t_u64 n);

/**
 * @brief Computes the power of a double-precision floating-point number.
 *
 * This function raises a double-precision floating-point number
 * to the power of an unsigned integer.
 *
 * @param x Base value.
 * @param n Exponent value.
 * @return Result of x raised to the power of n.
 */
double			ft_dpow(double x, t_u64 n);

/**
 * @brief Rounds a floating-point number to the nearest integer.
 *
 * This function rounds a floating-point number to the nearest integer value.
 *
 * @param x Input number.
 * @return Rounded number.
 */
float			ft_roundff(float x);

/**
 * @brief Computes the absolute value of a double-precision
 * floating-point number.
 *
 * This function calculates the absolute value
 * of a double-precision floating-point number.
 *
 * @param x Input number.
 * @return Absolute value of the input number.
 */
double			ft_fabs(double x);

/**
 * @brief Fast sine function using lookup table (degrees).
 *
 * This function calculates sine using a precomputed lookup table
 * for integer degrees, with linear interpolation for precision.
 * Optimized for raycasting operations.
 *
 * @param degrees Angle in degrees.
 * @return Sine value.
 */
float			ft_sin_deg(float degrees);

/**
 * @brief Fast cosine function using lookup table (degrees).
 *
 * This function calculates cosine using a precomputed lookup table
 * for integer degrees, with linear interpolation for precision.
 * Optimized for raycasting operations.
 *
 * @param degrees Angle in degrees.
 * @return Cosine value.
 */
float			ft_cos_deg(float degrees);

/**
 * @brief Converts degrees to radians using bit manipulation.
 *
 * This function performs fast degree to radian conversion
 * using optimized floating-point operations.
 *
 * @param degrees Angle in degrees.
 * @return Angle in radians.
 */
float			ft_deg_to_rad(float degrees);

/**
 * @brief Normalizes angle to 0-360 degree range using bit tricks.
 *
 * This function normalizes an angle to the 0-360 degree range
 * using optimized modulo operations.
 *
 * @param degrees Input angle in degrees.
 * @return Normalized angle in 0-360 range.
 */
float			ft_normalize_deg(float degrees);

#endif
