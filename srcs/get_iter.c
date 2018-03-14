/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:29:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 14:28:16 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_break	get_itr(t_cmplx (*iter)(t_cmplx z, t_cmplx z2, t_cmplx to_add),
		t_cmplx c, short max_iterations, t_cmplx to_add)
{
	t_break point;
	t_cmplx z;

	z.re = c.re;
	z.im = c.im;
	point.iter = 0;
	point.val.re = 0;
	point.val.im = 0;
	while(point.iter < max_iterations)
	{
		point.val.re = z.re * z.re;
		point.val.im = z.im * z.im;
		if (point.val.re + point.val.im > 4)
			return(point);
		point.iter++;
		z = (*iter)(z, point.val, to_add);
	}
	return (point);
}
