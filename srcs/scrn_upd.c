/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_upd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:43:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/16 19:02:54 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_help(t_frct *frct)
{
	mlx_string_put(frct->mlx, frct->win, 5, 20, WHITE, HELP_1);
	mlx_string_put(frct->mlx, frct->win, 5, 35, WHITE, HELP_2);
	mlx_string_put(frct->mlx, frct->win, 5, 50, WHITE, HELP_3);
	mlx_string_put(frct->mlx, frct->win, 5, 65, WHITE, HELP_4);
	mlx_string_put(frct->mlx, frct->win, 5, 80, WHITE, HELP_5);
	mlx_string_put(frct->mlx, frct->win, 5, 95, WHITE, HELP_6);
	mlx_string_put(frct->mlx, frct->win, 5, 110, WHITE, HELP_7);
	mlx_string_put(frct->mlx, frct->win, 5, 125, WHITE, HELP_8);
	mlx_string_put(frct->mlx, frct->win, 5, 140, WHITE, HELP_9);
	mlx_string_put(frct->mlx, frct->win, 5, 155, WHITE, HELP_10);
	mlx_string_put(frct->mlx, frct->win, 5, 170, WHITE, HELP_11);
	mlx_string_put(frct->mlx, frct->win, 5, 185, WHITE, HELP_12);
	mlx_string_put(frct->mlx, frct->win, 5, 200, WHITE, HELP_13);
	mlx_string_put(frct->mlx, frct->win, 5, 215, WHITE, HELP_14);
	mlx_string_put(frct->mlx, frct->win, 5, 230, WHITE, HELP_15);
	mlx_string_put(frct->mlx, frct->win, 5, 245, WHITE, HELP_16);
	mlx_string_put(frct->mlx, frct->win, 5, 260, WHITE, HELP_17);
}

static void	set_pixel(short x, short y, t_break p, t_frct *frct)
{
	if (p.iter < frct->max_iterations)
		SET_PIX(x, y, (&frct->img),
			frct->get_pxl_clr(frct->max_iterations, p));
	else
		SET_PIX(x, y, (&frct->img), 0);
}

static void	*calc_frct(void *param)
{
	t_thrd_inpt	*v;
	t_cmplx		c;
	short		x;
	short		y;
	t_cmplx		to_add;

	v = (t_thrd_inpt *)param;
	y = v->from;
	c.im = v->frct->min.im + y * v->frct->step.im;
	while (y < v->to)
	{
		x = 0;
		c.re = v->frct->min.re;
		while (x < IMG_WIDTH)
		{
			c.re += v->frct->step.re;
			to_add = v->frct->is_julia ? v->frct->julia_const : c;
			set_pixel(x, y, get_itr(v->frct->iter, c,
						v->frct->max_iterations, to_add), v->frct);
			x++;
		}
		c.im += v->frct->step.im;
		y++;
	}
	pthread_exit(0);
}

void		draw_frct(t_frct *frct, t_thrd_inpt *mlst)
{
	int				i;
	pthread_t		th_id[THREAD_NUM];

	frct->step.re = frct->range.re / (IMG_WIDTH - 1);
	frct->step.im = frct->range.im / (IMG_HEIGHT - 1);
	frct->mov_coeff.re = frct->step.re * ZOOM_COEFF;
	frct->mov_coeff.im = frct->step.im * ZOOM_COEFF;
	i = -1;
	while (++i < THREAD_NUM)
		pthread_create(&th_id[i], NULL, calc_frct, mlst + i);
	i = -1;
	while (++i < THREAD_NUM)
		pthread_join(th_id[i], NULL);
	mlx_put_image_to_window(frct->mlx, frct->win, frct->img.pnt_img, 0, 0);
}

void		scrn_upd(t_frct *frct)
{
	t_thrd_inpt	*mlst;

	mlst = (t_thrd_inpt *)frct->mlst_p;
	draw_frct(frct, mlst);
	mlx_string_put(frct->mlx, frct->win, 15, 0, WHITE, "f1 - help");
	if (frct->show_help)
		print_help(frct);
}
