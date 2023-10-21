/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/10/21 02:57:57 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int32_t main(int32_t argc, const char* argv[])
{
	(void) argc;
	(void) argv;
	
	mlx_t* mlx;
	static mlx_image_t* image;	
	//uint32_t color = 0xFF0000FF;
	
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 1920, 1080)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

    //mlx_put_pixel(image, 100, 100, color);

	mlx_loop_hook(mlx, ft_pixels, image);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}