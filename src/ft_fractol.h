/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/11/15 04:33:50 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define MLX_ERROR 1

#endif

typedef struct
{
    double	real;
    double	imag;
} t_complex;

void ft_hook(void* param); //manipula eventos do teclado
void ft_pixels(mlx_image_t *image);
uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int main();
int square(t_complex num);
t_complex multiplica_complexos(t_complex z, t_complex c);
t_complex soma_complexos(t_complex z, t_complex c);
int ft_mandelbrot(t_complex c, int max_iterations);
