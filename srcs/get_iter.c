/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:29:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/26 19:12:41 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

//senya will be dissapointed

int		get_itr_mandelbrot(t_frct *frct, t_cmplx c)
{
	int	n;

	t_cmplx z;
	t_cmplx z2;

	z.re = c.re;
	z.im = c.im;
	n = 0;
	while(n < frct->max_iterations)
	{
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		if (z2.re + z2.im > 4)
			break;
				n++;
		(*frct->iter)(&z, z2, c);
	}
	return (n);
}

int		get_itr_julia(t_frct *frct, t_cmplx c)
{
	int	n;

	t_cmplx z;
	t_cmplx z2;

	z.re = c.re;
	z.im = c.im;
	n = 0;
	while(n < frct->max_iterations)
	{
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		if (z2.re + z2.im > 4)
			break;
				n++;
		frct->iter(&z, z2, frct->julia_const);
	}
	return (n);
}
