/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:56:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/11 18:14:16 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mov_up_key(t_frct *frct)
{
	frct->min.im -= frct->mov_coeff.im;
	frct->max.im -= frct->mov_coeff.im;
}

void	mov_down_key(t_frct *frct)
{
	frct->min.im += frct->mov_coeff.im;
	frct->max.im += frct->mov_coeff.im;
}

void	mov_left_key(t_frct *frct)
{
	frct->min.re -= frct->mov_coeff.re;
	frct->max.re -= frct->mov_coeff.re;
}

void	mov_right_key(t_frct *frct)
{
	frct->min.re += frct->mov_coeff.re;
	frct->max.re += frct->mov_coeff.re;
}
