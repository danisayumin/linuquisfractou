/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/01 21:23:03 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define MLX_ERROR 1
#define IMAGE 1024
#define MAX_ITER 100
#endif

typedef struct
{
    double	real;
    double	imag;
} t_complex;

void ft_hook(void* param); //manipula eventos do teclado
void ft_pixels(mlx_image_t *image, char *argv[]);
uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int main(int ac, char **av);
t_complex multiplica_complexos(t_complex z, t_complex c);
t_complex soma_complexos(t_complex z, t_complex c);
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
t_complex ft_mandelbrot(t_complex c, t_complex v);
double map(int num, double in_min, double in_max, double out_min, double out_max);
int ft_calculate_mandelbrot(t_complex c, double real_part, double complex_part);
