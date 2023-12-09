/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/09 00:45:03 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int main(int argc, char *argv[])
{
    mlx_t *mlx;
    mlx_image_t *image;

    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
        mlx = mlx_init(1024, 1024, "MANDELBROT", true);
    else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
    {
        // Criação da janela para o conjunto de Julia
        mlx = mlx_init(1024, 1024, "JULIA", true);
    }
    else
    {
        // Caso de erro
        mlx = mlx_init(1024, 1024, "FUDEU", true);
        ft_putstr_fd("DEU RUIM AQUI", 2);
        return (EXIT_FAILURE);
    }

    image = mlx_new_image(mlx, IMAGE, IMAGE);

    // Configurações iniciais da imagem
    t_image_info info = {
        .mlx = mlx,
        .image = image,
        .scale_x = 1.0,
        .scale_y = 1.0,
        .offset_x = 0.0,
        .offset_y = 0.0,
    };

    // Chama a função de renderização inicial
    ft_pixels(&info);

    // Configura o hook de teclado
    mlx_key_hook(mlx, (mlx_keyfunc)ft_key_hook, &info);
	#ifdef MLX42
		mlx_put_image(mlx, image, 0, 0); //n sei se funfa
	#else
		mlx_image_to_window(mlx, image, 0, 0);
	#endif

    mlx_loop(mlx);

    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}