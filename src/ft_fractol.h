/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/09 11:12:45 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include <stdio.h> //debug
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define MLX_ERROR 1
#define IMAGE 1024
#define MAX_ITER 100
#define KEY_PLUS 43  // Código ASCII para '+'
#define KEY_MINUS 45 // Código ASCII para '-'

#endif

typedef struct
{
    double	real;
    double	imag;
} t_complex;

typedef struct s_color {
    uint32_t r;
    uint32_t g;
    uint32_t b;
} t_color;

typedef enum {
    MANDELBROT,
    JULIA
} t_fractal_type;

typedef struct s_image_info
{
    mlx_t *mlx;
    mlx_image_t *image;
    double scale_x;
    double scale_y;
    double offset_x;
    double offset_y;
	t_fractal_type current_fractal;
	t_complex julia_constant;
} t_image_info;

void ft_pixels(t_image_info *info);
uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
t_complex multiplica_complexos(t_complex z, t_complex c);
t_complex soma_complexos(t_complex z, t_complex c);
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
t_complex ft_mandelbrot(t_complex c, t_complex v);
double map(int num, double in_min, double in_max, double out_min, double out_max);
int ft_calculate_mandelbrot(t_complex c, double real_part, double complex_part);
int if_mandelbrot(t_complex c);
void ft_key_hook(mlx_key_data_t key, t_image_info *info);
t_complex ft_julia(t_complex z, t_complex c);
int if_julia(t_complex c, t_complex z, int max_iter);

