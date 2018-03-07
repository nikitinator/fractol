/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:54:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/07 22:05:22 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>//

void	apply_zoom(t_frct *frct, long double zoom_coeff)
{
	t_cmplx	center;

	center.re = frct->range.re / 2 + frct->min.re;	
	center.im = frct->range.im / 2 + frct->min.im;	
	frct->range.re *= (1 + zoom_coeff); 
	frct->range.im *= (1 + zoom_coeff); 
	frct->min.re = center.re - frct->range.re / 2;
	frct->max.re = center.re + frct->range.re / 2;
	frct->min.im = center.im - frct->range.im / 2;
	frct->max.im = center.im + frct->range.im / 2;
}

void	zoom_in_key(t_frct *frct)
{
	apply_zoom(frct, -frct->zoom_coeff);
}

void	zoom_out_key(t_frct *frct)
{
	apply_zoom(frct, frct->zoom_coeff);
}
