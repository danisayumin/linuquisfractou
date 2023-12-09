/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/09 11:44:31 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_complex ft_julia(t_complex z, t_complex c)
{
    return soma_complexos(multiplica_complexos(z, z), c);
}

int if_julia(t_complex c, t_complex z, int max_iter)
{
    int i = 0;
    while (i < max_iter)
    {
        z = ft_julia(z, c);
        if (z.real * z.real + z.imag * z.imag > 400)
            return i;
        i++;
    }
    return 0;
}
