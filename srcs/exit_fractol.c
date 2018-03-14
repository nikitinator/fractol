/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:30:10 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 16:19:37 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_frct(t_frct *frct)
{
	mlx_destroy_image(frct->mlx, frct->img.pnt_img);
	mlx_destroy_window(frct->mlx, frct->win);
	exit(1);
}
