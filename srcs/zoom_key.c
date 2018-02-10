/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:54:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/09 18:44:19 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in_key(t_frct *frct)
{
	frct->min_re /= frct->zoom_re_val;
	frct->max_re /= frct->zoom_re_val;
	frct->min_im /= frct->zoom_im_val;
	frct->max_im /= frct->zoom_im_val;
}

void	zoom_out_key(t_frct *frct)
{
	frct->min_re *= frct->zoom_re_val;
	frct->max_re *= frct->zoom_re_val;
	frct->min_im *= frct->zoom_im_val;
	frct->max_im *= frct->zoom_im_val;
}
