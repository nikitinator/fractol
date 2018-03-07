/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:35:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/07 17:39:33 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterate_perp_celtic(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re) * z->im + to_add.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;
}

void	iterate_burn_ship(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re * z->im) + to_add.im;
	z->re = z2.re - z2.im + to_add.re;
}

void	iterate_heart_brot(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * fabsl(z->re) * z->im + to_add.im;
	z->re = z2.re - z2.im + to_add.re;
}

void	iterate_perp_burn_ship(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * fabsl(z->im) + to_add.im;
	z->re = z2.re - z2.im + to_add.re;
}

void	iterate_buffalo(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * fabsl(z->re * z->im) + to_add.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;
}
