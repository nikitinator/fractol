/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:30:10 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/09 13:56:43 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_frct(t_frct *frct)
{
//	size_t		i;

//	i = 0;
//	while (i < frct->pxls.row)
//	{
//		if (frct->pxls.arr[i])
//			free(frct->pxls.arr[i]);
//		i++;
//	}
//	if (frct->pxls.arr)
//		free(frct->pxls.arr);
	mlx_destroy_image(frct->mlx, frct->img.pnt_img);
	mlx_destroy_window(frct->mlx, frct->win);
	exit(1);
}
