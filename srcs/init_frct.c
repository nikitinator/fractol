/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:42:54 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/28 21:59:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_frct_img(t_img *img, void *mlx_ptr)
{
	img->pnt_img = mlx_new_image(mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img->arr =
		mlx_get_data_addr(img->pnt_img, &img->bi_pp,
				&img->size_line, &img->endian);
	img->by_pp = img->bi_pp / 8;
	img->center[X] = IMG_HEIGHT / 2;
	img->center[Y] = IMG_WIDTH / 2;
}

void		set_milestones(t_thrd_inp *milestones, t_frct *frct)
{
	int		i;

	if (THREAD_NUM > 0)
	{
		i = -1;
		while (i++ < THREAD_NUM)
		{
			milestones[i].frct = frct;
			milestones[i].borders[FROM] = IMG_HEIGHT / THREADS * i;//
			milestones[i].borders[TO] =	IMG_HEIGHT / THREADS * i + 1;//

			frct->milestones[THREADS] = IMG_HEIGHT;
		}
	}
}

void	init_frct(t_frct *frct, int index_frct, int index_iter)
{
	t_frct_itr_data	*data_itr;

	data_itr = get_frct_itr_data();
	init_frct_img(&frct->img, frct->mlx);
	frct->show_help = 0;
	frct->min.re = DFLT_MIN_RE;
	frct->max.re = DFLT_MAX_RE;
	frct->min.im = DFLT_MAX_IM; 
	frct->max.im = DFLT_MIN_IM; 
	frct->range.im = frct->max.im - frct->min.im;
	frct->range.re = frct->max.re - frct->min.re; 
	frct->zoom_coeff = 0.1 ;
	frct->mov_coeff.im = frct->range.im / 80;
	frct->mov_coeff.re = frct->range.re / 80;
	frct->max_iterations = 50;
	frct->julia_const = (t_cmplx){0.0, 0.0};
	frct->iter = data_itr[index_iter - 1].iter;
	if (index_frct == 1)
		frct->get_iter = get_itr_mandelbrot;
	else if (index_frct == 2)
		frct->get_iter = get_itr_julia;
	frct->get_pxl_clr = get_pxl_clr_1;
	set_milestones(frct);
}
