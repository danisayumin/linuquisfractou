/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/10 17:07:45 by dsayumi-         ###   ########.fr       */
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
	if (info.current_fractal == JULIA)
	{
		printf("DEBUG: Entrou no bloco JULIA\n");
		if (argc >= 4)
		{
			printf("DEBUG: Entrou no bloco JULIA argc >= 4\n");
			info.julia_constant.real = atof(argv[3]);
		}
		if (argc >= 5)
		{
			printf("DEBUG: Entrou no bloco JULIA argc >= 5\n");
			info.julia_constant.imag = atof(argv[4]);
		}
	}
	initialize_image(&info);
	mlx_key_hook(mlx, (mlx_keyfunc)ft_key_hook, &info);
}

t_fractal_type	determine_fractal_type(int argc, char *argv[])
{
	printf("DEBUG: argc = %d, argv[1] = %s\n", argc, argv[1]);
	if ((argc == 2 && !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		printf("DEBUG: Entrou no bloco JULIA\n");
		return (JULIA);
	}
	else
	{
		printf("DEBUG: Entrou no bloco MANDELBROT\n");
		return (MANDELBROT);
	}
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
