/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 01:06:28 by danielasayu       #+#    #+#             */
/*   Updated: 2023/12/10 16:24:27 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

uint32_t	ft_pixel(uint32_t r, uint32_t g, uint32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	generate_gradient_palette(t_color colors[], int num_colors,
		t_color palette[])
	{
	float	step_r;
	float	step_b;
	float	step_g;
	int		i;

	step_r = (float)(colors[1].r - colors[0].r) / (num_colors - 1);
	step_g = (float)(colors[1].g - colors[0].g) / (num_colors - 1);
	step_b = (float)(colors[1].b - colors[0].b) / (num_colors - 1);
	i = 0;
	while (i < num_colors)
	{
		palette[i] = (t_color){(int)(colors[0].r + i * step_r),
			(int)(colors[0].g + i * step_g),
			(int)(colors[0].b + i * step_b)};
		i++;
	}
}

t_complex	ft_init_c(uint32_t x, uint32_t y, t_image_info *info)
{
	t_range	in_x ;
	t_range	in_y ;
	t_range	out_x;
	t_range	out_y;

	in_x = (t_range){0, IMAGE};
	in_y = (t_range){0, IMAGE};
	out_x = (t_range){-2.5 / info->scale_x + info->offset_x,
		1.5 / info->scale_x + info->offset_x};
	out_y = (t_range){-1.5 / info->scale_y + info->offset_y,
		2.5 / info->scale_y + info->offset_y};
	return ((t_complex){map(x, in_x, out_x), map(y, in_y, out_y)});
}

void	ft_pixels(t_image_info *info)
{
	t_color		*colors;
	t_color		palette[42];
	uint32_t	x;
	uint32_t	y;

	colors = (t_color[5]){{0, 0, 0}, {0, 255, 255}, {255, 0, 255},
	{255, 255, 0}, {255, 255, 255}};
	x = 0;
	generate_gradient_palette(colors, 42, palette);
	while (x < IMAGE)
	{
		y = 0;
		while (y < IMAGE)
		{
			ft_verify_fractal(x, y, info, palette);
			y++;
		}
		x++;
	}
}

void	ft_verify_fractal(uint32_t x, uint32_t y,
			t_image_info *info, t_color palette[])
{
	t_color		interpolated_color;
	int			i;

	if (info->current_fractal == MANDELBROT)
		i = if_mandelbrot(ft_init_c(x, y, info));
	else if (info->current_fractal == JULIA)
		i = if_julia(info->julia_constant, ft_init_c(x, y, info), MAX_ITER);
	else
		i = 0;
	interpolated_color = palette[i];
	mlx_put_pixel(info->image, x, y, ft_pixel(interpolated_color.r,
			interpolated_color.g, interpolated_color.b));
}
