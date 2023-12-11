/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/11 05:53:00 by dsayumi-         ###   ########.fr       */
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

void	initialize_info(t_image_info *info, int argc, char *argv[])
{
	info->mlx = NULL;
	info->image = NULL;
	info->scale_x = 1.0;
	info->scale_y = 1.0;
	info->offset_x = 0.0;
	info->offset_y = 0.0;
	info->current_fractal = determine_fractal_type(argc, argv);
	if (info->current_fractal == JULIA && argc >= 3)
	{
		if (!is_valid_number(argv[2]))
		{
			ft_putstr_fd("Invalid Julia constant real part.\n", 2);
			exit(EXIT_FAILURE);
		}
			info->julia_constant.real = atof(argv[2]);
		if (info->current_fractal == JULIA && argc >= 4)
		{
			if (!is_valid_number(argv[3]))
			{
				ft_putstr_fd("Invalid Julia constant imaginary part.\n", 2);
				exit(EXIT_FAILURE);
			}
		}
			info->julia_constant.imag = atof(argv[3]);
	}
}

t_fractal_type	determine_fractal_type(int argc, char *argv[])
{
	if ((argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		return (JULIA);
	}
	else
		return (MANDELBROT);
}

int	main(int argc, char *argv[])
{
	t_image_info	*info;

	if ((argc == 4 && (!ft_strncmp(argv[1], "julia", 5)))
		|| (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10))))
	{
		info = malloc(sizeof(t_image_info));
		initialize_info(info, argc, argv);
		info->mlx = mlx_init(1024, 1024,
				fractal_type_to_str(determine_fractal_type(argc, argv)), true);
		initialize_image(info);
		mlx_key_hook(info->mlx, (mlx_keyfunc)ft_key_hook, info);
		mlx_scroll_hook(info->mlx, (mlx_scrollfunc)ft_scroll_hook, info);
		mlx_loop(info->mlx);
		mlx_terminate(info->mlx);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol [fractal type] [julia constant]\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
