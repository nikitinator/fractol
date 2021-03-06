/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_frct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:10:24 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 14:07:09 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_frct(t_frct *frct)
{
	frct->min.re = DEFAULT_MIN_RE;
	frct->max.re = DEFAULT_MAX_RE;
	frct->min.im = DEFAULT_MAX_IM;
	frct->max.im = DEFAULT_MIN_IM;
	frct->range.im = frct->max.im - frct->min.im;
	frct->range.re = frct->max.re - frct->min.re;
	frct->zoom_coeff = 0.1;
	frct->mov_coeff.im = frct->range.im / 80;
	frct->mov_coeff.re = frct->range.re / 80;
	frct->max_iterations = MAX_ITER_DEFAULT;
}
