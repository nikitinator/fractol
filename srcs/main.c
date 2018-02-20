/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/20 20:33:29 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "fractol.h"

int		handle_key(int keycode, t_frct *frct)
{
	int						i;
	static t_func_key_hook	func[9] = {
		{BUT_ESC, exit_frct},
		{BUT_UP, mov_up_key},
		{BUT_DOWN, mov_down_key},
		{BUT_RIGHT, mov_right_key},
		{BUT_LEFT, mov_left_key},
		{BUT_PLU, zoom_in_key}, 
		{BUT_MIN, zoom_out_key},
		{BUT_BIGG, incr_iteration_num},
		{BUT_LESS, decr_iteration_num}
		};

	i = 0;
	while (i < 9 && func[i].key != keycode)
		i++;
	if (i < 9)
		func[i].f(frct);
	scrn_upd(frct);
	return (0);
}

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

void		set_milestones(t_frct *frct)
{
	int		i;

	if (THREADS > 0)
	{
		i = -1;
		while (i++ < THREADS)
			frct->milestones[i] = IMG_HEIGHT / THREADS * i;//
		frct->milestones[THREADS] = IMG_HEIGHT;
	}
}


void	init_frct(t_frct *frct)
{
	init_frct_img(&frct->img, frct->mlx);
	frct->show_help = 0;
	frct->min.re = -2.0;//-2.0;
	frct->max.re = 	2.0; // 1.0;
	frct->min.im =  -2.0;//-1.2;
	frct->max.im =  2.0;// 1.2;//ct->min.im + (frct->max.re - frct->min.re) * IMG_HEIGHT / IMG_WIDTH;
	frct->range.im = frct->max.im - frct->min.im;
	frct->range.re = frct->max.re - frct->min.re; 
	frct->zoom_coeff = 0.05 ;
	frct->mov_coeff.im = frct->range.im / 80;
	frct->mov_coeff.re = frct->range.re / 80;
	frct->max_iterations = 50;	
	set_milestones(frct);
}

int		mouse_zoom(int key, int x, int y, t_frct *frct)
{
	t_cmplx	mouse;
	t_cmplx	ratio;

	printf("x: %d\t\t y: %d\n", x, y);
	mouse.re = (double)x / (IMG_WIDTH /
		(frct->max.re - frct->min.re)) + frct->min.re;
	mouse.im = (double)y / (IMG_HEIGHT /
			(frct->max.im - frct->min.im)) + frct->min.im;
	
	ratio.re = 1.0 / IMG_WIDTH  * (float)x;	
	ratio.im = 1.0 / IMG_HEIGHT * (float)y;  	

	printf("mouse_im: %Lf\n",mouse.im);
	printf("mouse_re: %Lf\n",mouse.re);

	printf("1 ratio_im: %Lf\n",ratio.im);
	printf("1 ratio_re: %Lf\n",ratio.re);

	printf("range.im: %Lf\n", frct->range.im);
	printf("range.re: %Lf\n", frct->range.re);
	//zoom_in_key(frct);

	if (key == 1 || key == 4)
	{
		//zoom_in_key(frct);
		frct->range.re *= (1 - frct->zoom_coeff);
		frct->range.im *= (1 - frct->zoom_coeff);
		
	}
	else if (key == 2 || key == 5)
	{
		//zoom_out_key(frct);
		frct->range.re *= (1 + frct->zoom_coeff);
		frct->range.im *= (1 + frct->zoom_coeff);
	}

	frct->min.re = mouse.re - frct->range.re * ratio.re;
	frct->max.re = mouse.re + frct->range.re * (1 - ratio.re);
	frct->min.im = mouse.im - frct->range.im * ratio.im;
	frct->max.im = mouse.im + frct->range.im * (1 - ratio.im);

	printf("frct->min.re:%Lf\n", frct->min.re);
	printf("frct->max.re:%Lf\n", frct->max.re);
	printf("frct->min.im:%Lf\n", frct->min.im);
	printf("frct->max.im:%Lf\n", frct->max.im);
	scrn_upd(frct);
	ft_putendl("");
	return (0);
}

int		main(int argc, char **argv)
{
	t_frct	frct;

	if (argc > 1)
	{
		(void)argv;
		if (!(frct.mlx = mlx_init()))
			return (-1);
		if (!(frct.win = mlx_new_window(frct.mlx,
						IMG_WIDTH, IMG_HEIGHT, "mlx 42")))
			return (-1);
		init_frct(&frct);
		scrn_upd(&frct);
		mlx_hook(frct.win, 2, 0, handle_key, &frct);
		mlx_hook(frct.win, 17, 0, (int (*)(void *))exit_frct, &frct);
		mlx_hook(frct.win, 4, 0, mouse_zoom ,&frct);
	//	mlx_hook(frct.win, 5, 0,       ,frct);
	//	mlx_hook(frct.win, 6, 0, get_coordinates ,&frct);
		mlx_loop(frct.mlx);
	}
	ft_putendl_fd("Usage : ./frct <filename>", 2);
	return (0);
}
