/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:54:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/15 17:08:36 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>//

void	zoom_in_key(t_frct *frct)
{
	frct->min_re *= 1.05;//frct->zoom_re_val;
	frct->max_re *= 1.05;//frct->zoom_re_val;
	frct->min_im *= 1.05;//frct->zoom_im_val;
	frct->max_im *= 1.05;//frct->zoom_im_val;
ft_putendl("__");
	printf("frct->min_re:%Lf\n", frct->min_re);
	printf("frct->max_re:%Lf\n", frct->max_re); scrn_upd(frct);
	printf("frct->min_im:%Lf\n", frct->min_im); 
   printf("frct->max_im:%Lf\n", frct->max_im);
	ft_putendl("__");
	ft_putendl("__");
}

void	zoom_out_key(t_frct *frct)
{
	frct->min_re *= 0.95;//frct->zoom_re_val;
	frct->max_re *= 0.95;//frct->zoom_re_val;
	frct->min_im *= 0.95;//frct->zoom_im_val;
	frct->max_im *= 0.95;//frct->zoom_im_val;
ft_putendl("__");
	printf("frct->min_re:%Lf\n", frct->min_re);
	printf("frct->max_re:%Lf\n", frct->max_re); scrn_upd(frct);
	printf("frct->min_im:%Lf\n", frct->min_im); 
   printf("frct->max_im:%Lf\n", frct->max_im);
	ft_putendl("__");
ft_putendl("__");
}
