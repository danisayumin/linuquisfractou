/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/11/14 02:03:10 by danielasayu      ###   ########.fr       */
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

void ft_hook(void* param); //manipula eventos do teclado
void ft_pixels(mlx_image_t *image);
uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int main();

#define GREEN_PIXEL 0xFF00

typedef struct
{
    double	real;
    double	imag;
} t_complex;
