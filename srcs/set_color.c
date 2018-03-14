/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:11:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/13 16:21:15 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color_1(t_frct *frct)
{
	frct->get_pxl_clr = get_pxl_clr_1;
}

void	set_color_2(t_frct *frct)
{
	frct->get_pxl_clr = get_pxl_clr_2;
}

void	set_color_3(t_frct *frct)
{
	frct->get_pxl_clr = get_pxl_clr_3;
}
