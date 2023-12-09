/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:05 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/09 00:43:21 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int ft_key_hook(int key, t_image_info *info)
{
    if (key == KEY_PLUS)
    {
        // Zoom in
        info->scale_x *= 0.9;
        info->scale_y *= 0.9;
    }
    else if (key == KEY_MINUS)
    {
        // Zoom out
        info->scale_x /= 0.9;
        info->scale_y /= 0.9;
    }
    ft_pixels(info);
    return 0;
}