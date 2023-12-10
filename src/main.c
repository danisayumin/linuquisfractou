/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/10 16:20:03 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static const char	*fractal_type_to_str(t_fractal_type type)
{
	if (type == JULIA)
		return ("JULIA");
	else
		return ("MANDELBROT");
}

static	void	initialize_image(t_image_info *info)
{
	info->image = mlx_new_image(info->mlx, IMAGE, IMAGE);
	ft_pixels(info);
	mlx_image_to_window(info->mlx, info->image, 0, 0);
}

void	initialize_info(int argc, char *argv[], mlx_t *mlx)
{
	t_image_info	info;

	info = (t_image_info){.mlx = mlx, .image = NULL,
		.scale_x = 1.0, .scale_y = 1.0,
		.offset_x = 0.0, .offset_y = 0.0,
		.current_fractal = determine_fractal_type(argc, argv),
		.julia_constant = {0.285, 0.01},
	};
	initialize_image(&info);
	mlx_key_hook(mlx, (mlx_keyfunc)ft_key_hook, &info);
}

t_fractal_type	determine_fractal_type(int argc, char *argv[])
{
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		return (JULIA);
	}
	else
		return (MANDELBROT);
}

int	main(int argc, char *argv[])
{
	mlx_t	*mlx;

	if (argc != 2 && !(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
		return (EXIT_FAILURE);
	mlx = mlx_init(1024, 1024,
			fractal_type_to_str(determine_fractal_type(argc, argv)), true);
	if (!mlx)
	{
		ft_putstr_fd("DEU RUIM AQUI", 2);
		return (EXIT_FAILURE);
	}
	initialize_info(argc, argv, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
