/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/10/27 21:22:31 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WIDTH 640
#define HEIGHT 640

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#endif

void ft_hook(void* param); //manipula eventos do teclado
void ft_pixels(mlx_image_t *image);
uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int main();

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

#define GREEN_PIXEL 0xFF00

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

