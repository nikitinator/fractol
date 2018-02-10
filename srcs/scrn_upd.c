/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_upd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:43:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/10 14:42:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"//

static void	print_frct(void *mlx, void *win, t_img *img, t_frct *frct/**/)
{
	size_t	x;
	size_t	y;

	t_color	clr;
	clr.c_32 = 0;

	double	re_factor;
	double	im_factor;
	
	printf("frct->max_im: %Lf\n", frct->max_im);
	printf("frct->min_im: %Lf\n", frct->min_im);
	printf("frct->max_re: %Lf\n", frct->max_re);
	printf("frct->min_re: %Lf\n", frct->min_re);
	ft_putendl("____________________________________________");
	re_factor = (frct->max_re - frct->min_re) / (IMG_WIDTH - 1);
	im_factor = (frct->max_im - frct->min_im) / (IMG_HEIGHT - 1);
	ft_bzero(img->arr, IMG_HEIGHT * img->size_line);

	double	c_im;
	double	c_re;
	double	z_re;
	double	z_im;
	int		is_inside;

	double	z_re2;
	double	z_im2;
	
	size_t	n;

	printf("im_factor: %f\t re_factor:%f\n", im_factor, re_factor);
	y = 0;
	while (y < IMG_HEIGHT)
	{
		c_im = frct->max_im - y * im_factor;
		x = 0;
		while (x < IMG_WIDTH)
		{
			c_re = frct->min_re + x * re_factor;
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
				SET_PIX(x, y, img, clr.c_32);
			}			
			if (is_inside)
			{
				//SET_PIX(x,y, img, WHITE);
			}	
			x++;
		}
		y++;
	}
	SET_PIX(img->center[X],img->center[Y], img, 0x00000000);
	mlx_put_image_to_window(mlx, win, img->pnt_img, 0, 0);
}

void		scrn_upd(t_frct *frct)
{
	print_frct(frct->mlx, frct->win, &frct->img, frct);
}
