/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:07:56 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/07 17:38:58 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterate_default(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * z->re * z->im + to_add.im;
	z->re = z2.re - z2.im + to_add.re;
}

void	iterate_tricorn(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * z->im + to_add.im;
	z->re = z2.re - z2.im + to_add.re;
}

void	iterate_perp_brot(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re) * z->im + to_add.im;
	z->re = z2.re - z2.im + to_add.re;
}

void	iterate_celtic_brot(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * z->re * z->im + to_add.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;
}

void	iterate_celtic_bar(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * z->im + to_add.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;
}
