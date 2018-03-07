/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:36:01 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/07 17:40:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterate_celt_heart(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = 2 * fabsl(z->re) * z->im + to_add.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;
}

void	iterate_perp_buffalo(t_cmplx *z, t_cmplx z2, t_cmplx to_add)
{
	z->im = -2 * z->re * fabsl(z->im) + to_add.im;
	z->re = fabsl(z2.re - z2.im) + to_add.re;
}
