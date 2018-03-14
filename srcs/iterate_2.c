/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:35:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 15:12:15 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmplx	iterate_perp_celtic(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){-2 * fabsl(z.re) * z.im + to_add.im,
			fabsl(z2.re - z2.im) + to_add.re});
}

t_cmplx	iterate_burn_ship(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){-2 * fabsl(z.re * z.im) + to_add.im,
			z2.re - z2.im + to_add.re});
}

t_cmplx	iterate_heart_brot(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){2 * fabsl(z.re) * z.im + to_add.im,
			z2.re - z2.im + to_add.re});
}

t_cmplx	iterate_perp_brn_shp(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){-2 * z.re * fabsl(z.im) + to_add.im,
			z2.re - z2.im + to_add.re});
}

t_cmplx	iterate_buffalo(t_cmplx z, t_cmplx z2, t_cmplx to_add)
{
	return ((t_cmplx){-2 * fabsl(z.re * z.im) + to_add.im,
			fabsl(z2.re - z2.im) + to_add.re});
}
