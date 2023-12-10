/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:38:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/12/10 16:33:26 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_complex	ft_julia(t_complex z, t_complex c)
{
	return (soma_complexos(multiplica_complexos(z, z), c));
}

int	if_julia(t_complex c, t_complex z, int max_iter)
{
	int	i;

	i = 0;
	while (i < max_iter)
	{
		z = ft_julia(z, c);
		if (z.real * z.real + z.imag * z.imag > 400)
			return (i);
		i++;
	}
	return (0);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;
	int		deccount;

	res = 0;
	sign = 1;
	deccount = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		deccount = deccount * 10;
		str++;
	}
	return (res = res / deccount * sign);
}