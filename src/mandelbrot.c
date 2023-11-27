/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:16:28 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/11/16 01:43:46 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_complex multiplica_complexos(t_complex z, t_complex c)
{
    t_complex result;
    result.real = z.real * c.real - z.imag * c.imag;
    result.imag = z.real * c.imag + z.imag * c.real;
    return result;
}

t_complex soma_complexos(t_complex z, t_complex c)
{
    t_complex result;
    result.real = z.real + c.real;
    result.imag = z.imag + c.imag;
    return result;
}

t_complex   ft_mandelbrot(t_complex z, t_complex c)
{
    return soma_complexos(multiplica_complexos(z, z), c); // soma(mult(z, z), c)
}