/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/11 06:33:03 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_key_hook(mlx_key_data_t key, t_image_info *info)
{
	if (key.key == MLX_KEY_PAGE_DOWN)
		info->offset_y -= info->scale_y * 0.05;
	else if (key.key == MLX_KEY_K)
		info->offset_y += info->scale_y * 0.05;
	else if (key.key == MLX_KEY_J)
		info->offset_x -= info->scale_x * 0.05;
	else if (key.key == MLX_KEY_L)
		info->offset_x += info->scale_x * 0.05;
	else if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(info->mlx);
		exit(EXIT_SUCCESS);
	}
	ft_pixels(info);
}

void	ft_scroll_hook(double xdelta, double ydelta, t_image_info *info)
{
	if (ydelta > 0)
	{
		info->scale_x *= 0.9;
		info->scale_y *= 0.9;
	}
	else if (ydelta < 0)
	{
		info->scale_x /= 0.9;
		info->scale_y /= 0.9;
	}
	info->offset_x += xdelta * info->scale_x;
	ft_pixels(info);
}
