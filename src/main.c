/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/10 02:52:45 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static	void	initialize_image(t_image_info *info)
{
	info->image = mlx_new_image(info->mlx, IMAGE, IMAGE);
	ft_pixels(info);
	mlx_image_to_window(info->mlx, info->image, 0, 0);
}

void	initialize_info(int argc, mlx_t *mlx)
{
	t_image_info	info;

	info = (t_image_info){.mlx = mlx, .image = NULL,
		.scale_x = 1.0, .scale_y = 1.0,
		.offset_x = 0.0, .offset_y = 0.0,
		.current_fractal = ternarie(JULIA, MANDELBROT, (argc == 4)),
		.julia_constant = {0.285, 0.01},
	};
	initialize_image(&info);
	mlx_key_hook(mlx, (mlx_keyfunc)ft_key_hook, &info);
}

char	*ternarie(char *a, char *b, bool c)
{
	if (c)
		return (a);
	return (b);
}

int	main(int argc, char *argv[])
{
	mlx_t	*mlx;

	if (argc != 2 && !(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
		return (EXIT_FAILURE);
	mlx = mlx_init(1024, 1024, ternarie("JULIA", "MANDELBROT",
				(argc == 4)), true);
	if (!mlx)
	{
		ft_putstr_fd("DEU RUIM AQUI", 2);
		return (EXIT_FAILURE);
	}
	initialize_info(argc, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
