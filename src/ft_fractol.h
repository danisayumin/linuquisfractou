/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/10 16:56:07 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# define MLX_ERROR 1
# define IMAGE 1024
# define MAX_ITER 100
# define KEY_PLUS 43  // Código ASCII para '+'
# define KEY_MINUS 45 // Código ASCII para '-'

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_color;

typedef enum s_fractal_type
{
	MANDELBROT,
	JULIA
}	t_fractal_type;

typedef struct s_image_info
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	double			scale_x;
	double			scale_y;
	double			offset_x;
	double			offset_y;
	t_fractal_type	current_fractal;
	t_complex		julia_constant;
}	t_image_info;

typedef struct range
{
	double	min;
	double	max;
}	t_range;

void				ft_pixels(t_image_info *info);
uint32_t			ft_pixel(uint32_t r, uint32_t g, uint32_t b);
t_complex			multiplica_complexos(t_complex z, t_complex c);
t_complex			soma_complexos(t_complex z, t_complex c);
void				ft_putstr_fd(char *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
t_complex			ft_mandelbrot(t_complex c, t_complex v);
double				map(int num, t_range in, t_range out);
int					ft_calculate_mandelbrot(t_complex c, double real_part,
						double complex_part);
int					if_mandelbrot(t_complex c);
void				ft_key_hook(mlx_key_data_t key, t_image_info *info);
void				ft_scroll_hook(double xdelta, double ydelta,
						t_image_info *info);
t_complex			ft_julia(t_complex z, t_complex c);
int					if_julia(t_complex c, t_complex z, int max_iter);
t_fractal_type		determine_fractal_type(int argc, char *argv[]);
void				ft_verify_fractal(uint32_t x, uint32_t y,
						t_image_info *info, t_color palette[]);
double				ft_atof(char *str);

#endif
