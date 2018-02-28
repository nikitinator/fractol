/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:07:56 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/26 20:43:09 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterate_default(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * z->re * z->im + to_add.im; //c.im;
	z->re = z2.re - z2.im + to_add.re;//c.re;
}

void	iterate_tricorn(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * z->im + to_add.im; //c.im;
	z->re = z2.re - z2.im + to_add.re;//c.re;
}

void	iterate_perp_brot(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re) * z->im + to_add.im; //c.im;
	z->re = z2.re - z2.im + to_add.re;//c.re;
}


void	iterate_celtic_brot(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * z->re * z->im + to_add.im; //c.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;//c.re;
}


void	iterate_celtic_bar(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * z->im + to_add.im; //c.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;//c.re;
}


void	iterate_perp_celtic(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re) * z->im + to_add.im; //c.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;//c.re;
}


void	iterate_burn_ship(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re * z->im) + to_add.im; //c.im;
	z->re = z2.re - z2.im + to_add.re;//c.re;
}


void	iterate_heart_brot(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * fabsl(z->re) * z->im + to_add.im; //c.im;
	z->re = z2.re - z2.im + to_add.re;//c.re;
}

void	iterate_perp_burn_ship(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * fabsl(z->im) + to_add.im; //c.im;
	z->re = z2.re - z2.im + to_add.re;//c.re;
}

void	iterate_buffalo(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re * z->im) + to_add.im; //c.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;//c.re;
}

void	iterate_celt_heart(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * fabsl(z->re) * z->im + to_add.im; //c.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;//c.re;
}

void	iterate_perp_buffalo(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * fabsl(z->im) + to_add.im; //c.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;//c.re;
}
