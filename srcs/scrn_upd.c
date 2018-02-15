/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_upd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:43:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/15 21:49:24 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"//



//static void	print_frct(void *mlx, void *win, t_img *img, t_frct *frct/**/)
//{
//	size_t	x;
//	size_t	y;
//
//	t_color	clr;
//	clr.c_32 = 0;
//
//	printf("frct->max_im: %Lf\n", frct->max_im);
//	printf("frct->min_im: %Lf\n", frct->min_im);
//	printf("frct->max_re: %Lf\n", frct->max_re);
//	printf("frct->min_re: %Lf\n", frct->min_re);
//	ft_putendl("____________________________________________");
//	frct->re_factor = (frct->max_re - frct->min_re) / (IMG_WIDTH - 1);
//	frct->im_factor = (frct->max_im - frct->min_im) / (IMG_HEIGHT - 1);
//
//	double	c_im;
//	double	c_re;
//	double	z_re;
//	double	z_im;
//	int		is_inside;
//
//	double	z_re2;
//	double	z_im2;
//	
//	size_t	n;
//
//	printf("frct->im_factor: %f\t frct->re_factor:%f\n", frct->im_factor, frct->re_factor);
//	y = 0;
//	while (y < IMG_HEIGHT)
//	{
//		c_im = frct->max_im - y * frct->im_factor;
//		x = 0;
//		while (x < IMG_WIDTH)
//		{
//			c_re = frct->min_re + x * frct->re_factor;
//			z_re = c_re;
//			z_im = c_im;
//			is_inside = 1;
//			//printf("y: %zu\tx: %zu\t c_im:%f\t, c_re%f\t\n", y, x, c_im, c_re);
//			n = 0;
//			while(n < frct->max_iterations)
//			{
//				z_re2 = z_re * z_re;
//			   	z_im2 = z_im * z_im;
//				if (z_re2 + z_im2 > 4)
//				{
//					is_inside = 0;
//					break;
//				}
//				z_im = 2 * z_re * z_im + c_im;
//				z_re = z_re2 - z_im2 + c_re;
//				n++;
//			}
//			if (n < frct->max_iterations)
//			{
//				clr.c_8[B] = (n * 6) % 255;
//				SET_PIX(x, y, img, clr.c_32);
//			}			
//			if (is_inside)
//			{
//				//SET_PIX(x,y, img, WHITE);
//			}	
//			x++;
//		}
//		y++;
//	}
//	SET_PIX(img->center[X],img->center[Y], img, 0x00111111);
//	mlx_put_image_to_window(mlx, win, img->pnt_img, 0, 0);
//}


//create small structure for this 
static void	*calc_frct(void *param/**/)
{
	t_frct *frct;
	frct = (t_frct *)param;
	//printf("frct->max_im: %Lf\n", frct->max_im);
	//printf("frct->min_im: %Lf\n", frct->min_im);
	//printf("frct->max_re: %Lf\n", frct->max_re);
	//printf("frct->min_re: %Lf\n", frct->min_re);
	// ft_putendl("____________________________________________");
	frct->re_factor = (frct->max_re - frct->min_re) / (IMG_WIDTH - 1);
	frct->im_factor = (frct->max_im - frct->min_im) / (IMG_HEIGHT - 1);
	//printf("frct->im_factor: %f\t frct->re_factor:%f\n", frct->im_factor, frct->re_factor);

	int		thread;
	double	c_im;
	double	c_re;
	double	z_re;
	double	z_im;
	int		is_inside;
	double	z_re2;
	double	z_im2;
	size_t	n;

	size_t	x;
	size_t	y;
	t_color	clr;

	thread = frct->thread++;
	pthread_cond_signal(&frct->th_cond);
	clr.c_32 = 0;
	y = frct->milestones[thread];
	while (y < frct->milestones[thread + 1])
	{
		//c_im = frct->max_im - y * frct->im_factor;
		c_im = frct->min_im + y * frct->im_factor;
		x = 0;
		while (x < IMG_WIDTH)
		{
			c_re = frct->min_re + x * frct->re_factor;
			z_re = c_re;
			z_im = c_im;
			is_inside = 1;
			//printf("y: %zu\tx: %zu\t c_im:%f\t, c_re%f\t\n", y, x, c_im, c_re);
			n = 0;
			while(n < frct->max_iterations)
			{
				z_re2 = z_re * z_re;
			   	z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4)
				{
					is_inside = 0;
					break;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				n++;
			}
			if (n < frct->max_iterations)
			{
				clr.c_8[B] = (n * 6) % 255;
				SET_PIX(x, y, (&frct->img), clr.c_32);
			}			
		//	if (is_inside)
		//		SET_PIX(x,y, (&frct->img), WHITE);
			x++;
		}
		y++;
	}
	//SET_PIX(frct->img.center[X],frct->img.center[Y], frct->img, 0x00111111);
	pthread_exit(0);	
}


void		scrn_upd(t_frct *frct)
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
		pthread_create(&th_id[i], NULL, calc_frct, frct);
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
	//print_frct(frct->mlx, frct->win, &frct->img, frct);
	return ;
}
