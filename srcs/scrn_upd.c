/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_upd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:43:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/26 19:08:11 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"//

//create small structure for this 
static void	*calc_mndlbrt(void *param/**/)
{
	t_frct *frct;
	int		thread;
	t_cmplx c;
	size_t	x;
	size_t	y;
	int		n;

	frct = (t_frct *)param;
	frct->factor.re = (frct->max.re - frct->min.re) / (IMG_WIDTH - 1);//
	frct->factor.im = (frct->max.im - frct->min.im) / (IMG_HEIGHT - 1);//
	frct->mov_coeff.re = frct->factor.re * ZOOM_COEFF;
	frct->mov_coeff.im = frct->factor.im * ZOOM_COEFF;

	thread = frct->thread++;
	
	pthread_cond_signal(&frct->th_cond);
	y = frct->milestones[thread];
	c.im = frct->min.im + y * frct->factor.im;
	while (y < frct->milestones[thread + 1])
	{
		x = 0;
		c.re = frct->min.re;
		while (x < IMG_WIDTH)
		{
			c.re += frct->factor.re;
			n = frct->get_iter(frct, c);
			if (n < frct->max_iterations)
				SET_PIX(x, y, (&frct->img), 
						frct->get_pxl_clr(frct->max_iterations, n));
			else
				SET_PIX(x, y, (&frct->img), 0); 
			x++;
		}
		c.im += frct->factor.im;
		y++;
	}
	pthread_exit(0);	
}

void		draw_mandelbrot(t_frct *frct)
{
	int				i;
	pthread_t		th_id[THREADS];
	pthread_mutex_t	mutex;
	
	//ft_bzero(frct->img.arr, IMG_HEIGHT * frct->img.size_line);
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&frct->th_cond, NULL);
	i = 0;
	frct->thread = 0;
	while(i < THREADS)
	{
		pthread_create(&th_id[i], NULL, calc_mndlbrt, frct);
		i++;
		pthread_cond_wait(&frct->th_cond, &mutex);
	}
	i = 0;
	while(i < THREADS)
	{
		pthread_join(th_id[i], NULL);
		i++;
	}
	mlx_put_image_to_window(frct->mlx, frct->win, frct->img.pnt_img, 0, 0);
	return ;
}

void		scrn_upd(t_frct *frct)
{
	draw_mandelbrot(frct);
	//draw_julia(frct);
}
