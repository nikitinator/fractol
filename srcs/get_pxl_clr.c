/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pxl_clr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:33:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 15:09:07 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double		get_cont_index(int max_iter, t_cmplx max_val,
		double log_2)
{
	return (max_iter + 1 - (log_2 / (sqrt(max_val.re + max_val.im))) / log_2);
}

int			get_pxl_clr_1(int max_iterations, t_break p)
{
	t_color clr;
	double	t;

	t = (double)p.iter / (double)max_iterations;
	clr.c_8[R] = (int)(9 * (1 - t) * t * t * t * 255);
	clr.c_8[G] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	clr.c_8[B] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	clr.c_8[T] = 0;
	return (clr.c_32);
}

int			get_pxl_clr_2(int max_iterations, t_break p)
{
	t_color		clr;
	long double cont_index;

	(void)max_iterations;
	cont_index = get_cont_index(p.iter, p.val, log(2));
	clr.c_8[R] = (unsigned char)(sin(0.016 * cont_index + 4) * 230 + 25);
	clr.c_8[G] = (unsigned char)(sin(0.013 * cont_index + 2) * 230 + 25);
	clr.c_8[B] = (unsigned char)(sin(0.01 * cont_index + 1) * 230 + 25);
	clr.c_8[T] = 0;
	return (clr.c_32);
}

int			get_pxl_clr_3(int max_iterations, t_break p)
{
	t_color clr;
	int		n;
	int		nn;
	double	t;

	t = (double)p.iter / (double)max_iterations;
	n = (t * 255 * 255 * 255);
	clr.c_8[B] = n / (255 * 255);
	nn = n - clr.c_8[B] * 255 * 255;
	clr.c_8[R] = nn / 255;
	clr.c_8[G] = nn - clr.c_8[R] * 255;
	clr.c_8[T] = 0;
	return (clr.c_32);
}
