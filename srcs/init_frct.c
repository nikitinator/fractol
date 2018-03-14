/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:42:54 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 15:17:38 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		set_milestones(t_thrd_inpt *milestones, t_frct *frct)
{
	int		i;

	frct->mlst_p = milestones;
	if (THREAD_NUM > 0)
	{
		i = 0;
		while (i < THREAD_NUM)
		{
			milestones[i].frct = frct;
			milestones[i].from = IMG_HEIGHT / THREAD_NUM * i;
			milestones[i].to = IMG_HEIGHT / THREAD_NUM * (i + 1);
			i++;
		}
		milestones[THREAD_NUM - 1].to = IMG_HEIGHT;
	}
}

void		init_frct_img(t_img *img, void *mlx_ptr)
{
	img->pnt_img = mlx_new_image(mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img->arr =
		mlx_get_data_addr(img->pnt_img, &img->bi_pp,
				&img->size_line, &img->endian);
	img->by_pp = img->bi_pp / 8;
}

void		init_frct(t_frct *frct, int index_frct, int index_iter)
{
	t_frct_itr_data	*data_itr;

	data_itr = get_frct_itr_data();
	frct->iter = data_itr[index_iter - 1].iter;
	if (index_frct == 1)
		frct->is_julia = 0;
	else if (index_frct == 2)
		frct->is_julia = 1;
	init_frct_img(&frct->img, frct->mlx);
	frct->show_help = 0;
	reset_frct(frct);
	frct->julia_const = (t_cmplx){0.0, 0.0};
	frct->get_pxl_clr = get_pxl_clr_1;
}
