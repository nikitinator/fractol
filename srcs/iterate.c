/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:07:56 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 14:37:05 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmplx	iterate_default(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){2 * z.re * z.im + to_add.im, z2.re - z2.im + to_add.re});
}

t_cmplx	iterate_tricorn(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){-2 * z.re * z.im + to_add.im,
			z2.re - z2.im + to_add.re});
}

t_cmplx	iterate_perp_brot(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){-2 * fabsl(z.re) * z.im + to_add.im,
			z2.re - z2.im + to_add.re});
}

t_cmplx	iterate_celtic_brot(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){2 * z.re * z.im + to_add.im,
			fabsl(z2.re - z2.im) + to_add.re});
}

t_cmplx	iterate_celtic_bar(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){-2 * z.re * z.im + to_add.im,
			fabsl(z2.re - z2.im) + to_add.re});
}
