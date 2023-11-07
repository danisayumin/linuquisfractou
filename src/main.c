/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/10/27 21:27:08 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

// t_win_data    open_window(uint32_t win_width, uint32_t win_height)
// {
//     uint32_t    x;
//     uint32_t    y;
//     t_win_data    strt;

//     x = 0; 
//     y = 0;
//     strt.win_width = win_width;
//     strt.win_height = win_height;
//     strt.mlx = mlx_init(win_width, win_height, "CS:GO", true);
//     strt.img = mlx_new_image(strt.mlx, win_width, win_height);
//     mlx_image_to_window(strt.mlx, strt.img, x, y);
//     return (strt);
// }

int main()
{
	
	mlx_t* mlx;
	static mlx_image_t* image;	
	//uint32_t color = 0xFF0000FF;
	
	// if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	// {
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// if (!(image = mlx_new_image(mlx, 1920, 1080)))
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }

    //mlx_put_pixel(image, 100, 100, color);


    mlx = mlx_init(1024, 1024, "HAHAHAAHAHHAHHHAHA", true);
    image = mlx_new_image(mlx, 1024, 1024);
    mlx_image_to_window(mlx, image, 0, 0);
	
	ft_pixels(image);
	// mlx_loop_hook(mlx, ft_pixels, image);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	// mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}