/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:56:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/09 17:23:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mov_up_key(t_frct *frct)
{
	frct->min_im += frct->mov_im_val;
	frct->max_im += frct->mov_im_val;
}

void	mov_down_key(t_frct *frct)
{
	frct->min_im -= frct->mov_im_val;
	frct->max_im -= frct->mov_im_val;
}

void	mov_left_key(t_frct *frct)
{
	frct->min_re -= frct->mov_re_val;
	frct->max_re -= frct->mov_re_val;
}

void	mov_right_key(t_frct *frct)
{
	frct->min_re += frct->mov_re_val;
	frct->max_re += frct->mov_re_val;
}
