/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pxl_clr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:33:14 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/07 21:37:19 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <fractol.h>

int		get_pxl_clr_1(int max_iterations, int n)
{
	t_color clr;
	double	t ;

	t = (double)n/(double)max_iterations;
	clr.c_8[R] = (int)(9*(1-t)*t*t*t*255);
	clr.c_8[G] = (int)(15*(1-t)*(1-t)*t*t*255);
	clr.c_8[B] = (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);	
	clr.c_8[T] = 0;
	return (clr.c_32);
}
