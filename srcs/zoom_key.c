/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:54:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/20 22:21:47 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>//

//void	zoom_center_apply(t_frct *frct)
//{
//
//	double	center_re;
//	double 	center_im;
//
//	center_re = frct->range_re / 2 + frct->min_re;	
//	center_im = frct->range_im / 2 + frct->min_im;	
//
//	frct->min_re = IMG_WIDTH / 2 mouse_re - range_re * ratio_re;
//	frct->max_re = IMG_HEIGHT / 2mouse_re + range_re * (1 - ratio_re);
//	frct->min_im = mouse_im - range_im * ratio_im;
//	frct->max_im = mouse_im + range_im * (1 - ratio_im);
//}	

void	zoom_in_key(t_frct *frct)
{
	t_cmplx	center;
	
	center.re = frct->range.re / 2 + frct->min.re;	
	center.im = frct->range.im / 2 + frct->min.im;	
	frct->range.re *= (1 - frct->zoom_coeff); 
	frct->range.im *= (1 - frct->zoom_coeff); 
	//frct->mov_coeff.im *= (1 - frct->zoom_coeff); 
	//frct->mov_coeff.re *= (1 - frct->zoom_coeff); 
	frct->min.re = center.re - frct->range.re / 2;
	frct->max.re = center.re + frct->range.re / 2;
	frct->min.im = center.im - frct->range.im / 2;
	frct->max.im = center.im + frct->range.im / 2;
}

void	zoom_out_key(t_frct *frct)
{
	t_cmplx	center;

	center.re = frct->range.re / 2 + frct->min.re;	
	center.im = frct->range.im / 2 + frct->min.im;	
	frct->range.re *= (1 + frct->zoom_coeff); 
	frct->range.im *= (1 + frct->zoom_coeff); 
	//frct->mov_coeff.im *= frct->zoom_coeff; 
	//frct->mov_coeff.re *= frct->zoom_coeff; 
	frct->min.re = center.re - frct->range.re / 2;
	frct->max.re = center.re + frct->range.re / 2;
	frct->min.im = center.im - frct->range.im / 2;
	frct->max.im = center.im + frct->range.im / 2;
}
