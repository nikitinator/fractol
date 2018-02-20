/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_upd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:43:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/20 22:27:16 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"//


//create small structure for this 
static int	get_iterations_num(t_frct *frct, t_cmplx c)
{
	int	n;

	t_cmplx z;
	t_cmplx z2;

	z.re = c.re;
	z.im = c.im;
	n = 0;
	while(n < frct->max_iterations)
	{
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		if (z2.re + z2.im > 4)
			break;
		z.im = 2 * z.re * z.im + c.im;
		z.re = z2.re - z2.im + c.re;
		n++;
	}
	return (n);
}

static void	colorize_pixel(t_frct *frct, int n, size_t x, size_t y)
{
	t_color clr;

	clr.c_32 = 0;
	clr.c_8[B] = (n * 6) % 255;
	SET_PIX(x, y, (&frct->img), clr.c_32);
}

static void	*calc_mndlbrt(void *param/**/)
{
	t_frct *frct;
	int		thread;
	t_cmplx c;
	size_t	x;
	size_t	y;
	int		n;

	frct = (t_frct *)param;
	frct->re_factor = (frct->max.re - frct->min.re) / (IMG_WIDTH - 1);//
	frct->im_factor = (frct->max.im - frct->min.im) / (IMG_HEIGHT - 1);//
	thread = frct->thread++;
	pthread_cond_signal(&frct->th_cond);
	y = frct->milestones[thread];
	while (y < frct->milestones[thread + 1])
	{
		c.im = frct->min.im + y * frct->im_factor;
		x = 0;
		while (x < IMG_WIDTH)
		{
			c.re = frct->min.re + x * frct->re_factor;
			n = get_iterations_num(frct, c);
			if (n < frct->max_iterations)
				colorize_pixel(frct, n, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(0);	
}


//static void	*calc_julia(void *param/**/)
//{
//	t_frct *frct;
//	frct = (t_frct *)param;
//
//	frct->re_factor = (frct->max_re - frct->min_re) / (IMG_WIDTH - 1);
//	frct->im_factor = (frct->max_im - frct->min_im) / (IMG_HEIGHT - 1);
//
//	int		thread;
//	double	c_im;
//	double	c_re;
//	double	z_re;
//	double	z_im;
//	int		is_inside;
//	size_t	n;
//
//	size_t	x;
//	size_t	y;
//	t_color	clr;
//
//	double long const_re;
//	double long const_im;
//	double zoom = 1, moveX = 0, moveY = 0;
//
//	const_re = -0.7;
//	const_im = 0.27015;
//
//	thread = frct->thread++;
//	pthread_cond_signal(&frct->th_cond);
//	clr.c_32 = 0;
//	y = frct->milestones[thread];
//	while (y < frct->milestones[thread + 1])
//	{
//		//c_im = (y - IMG_HEIGHT/2) / (0.5 * zoom * IMG_HEIGHT) + moveY;
//		x = 0;
//		while (x < IMG_WIDTH)
//		{
//			c_im = (y - IMG_HEIGHT/2) / (0.5 * zoom * IMG_HEIGHT) + moveY;
//			c_re = 1.5 * (x - IMG_WIDTH/2) / (0.5 * zoom * IMG_WIDTH) + moveX;
//			is_inside = 1;
//			n = 0;
//			while(n < frct->max_iterations)
//			{
//				z_re = c_re * c_re - c_im * c_im + const_re;
//				z_im = c_re * 2 * c_im + const_im;
//				if (z_re * z_re + z_im * z_im > 4)
//				{
//					is_inside = 0;
//					break;
//				}
//				n++;
//			}
//			if (n < frct->max_iterations)
//			{
//				clr.c_8[R] = (n * 6) % 255;
//				clr.c_8[G] = 255;
//				clr.c_8[B] = 255;
//				SET_PIX(x, y, (&frct->img), clr.c_32);
//			}			
//			if (is_inside)
//				SET_PIX(x,y, (&frct->img), 0x00111111);
//			x++;
//		}
//		y++;
//	}
//	pthread_exit(0);	
//}

void		draw_mandelbrot(t_frct *frct)
{
	int				i;
	pthread_t		th_id[THREADS];
	pthread_mutex_t	mutex;
	
	ft_bzero(frct->img.arr, IMG_HEIGHT * frct->img.size_line);
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
