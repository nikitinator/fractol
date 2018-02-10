/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/09 19:32:46 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	toggle_show_help(t_frct *frct)
{
	if (frct->show_help)
		frct->show_help = 0;
	else
		frct->show_help = 1;
}

int		handle_key(int keycode, t_frct *frct)
{
	int						i;
	static t_func_key_hook	func[7] = {
		{BUT_ESC, exit_frct},
		{BUT_UP, mov_up_key},
		{BUT_DOWN, mov_down_key},
		{BUT_RIGHT, mov_right_key},
		{BUT_LEFT, mov_left_key},
		{BUT_PLU, zoom_in_key}, 
		{BUT_MIN, zoom_out_key}
		};

	i = 0;
	while (i < 7 && func[i].key != keycode)
		i++;
	if (i < 7)
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

void	init_frct(t_frct *frct)
{
	init_frct_img(&frct->img, frct->mlx);
	frct->show_help = 0;
	frct->min_re = -2.0;
	frct->max_re = 1.0;
	frct->min_im = -1.2;
	frct->max_im =  frct->min_im + (frct->max_re - frct->min_re) * IMG_HEIGHT / IMG_WIDTH;
	frct->zoom_re_val = 1.5 ;
	frct->zoom_im_val = 1.5;
	frct->mov_re_val = 0.05;
	frct->mov_im_val = 0.05;
	
	printf("zoom_re_val:%Lf\n", frct->zoom_re_val);
	printf("zoom_im_val:%Lf\n", frct->zoom_im_val);
	printf("mov_re_val :%Lf\n", frct->mov_re_val);
	printf("mov_im_val :%Lf\n", frct->mov_im_val);
}

int		get_coordinates(int x, int y, t_frct *frct)
{
	frct->mouse_x = x;
	frct->mouse_y = y;
	printf("x: %d,\ty: %d\n",x,y);
	return (0);
}


double	interpolate(double strart, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int		mouse_zoom(int x, int y, t_frct *frct)
{
	double mouseRe;
	double mouseIm;

	printf("x: %d\t\t y: %d\n", x, y);
	mouseRe = (double)x / (IMG_WIDTH / (frct->re_max - frct->re_min)) + frct->re_min;
	mouseIm = (double)y / (IMG_HEIGHT / (frct->im_max - frct->im_min)) + frct->im_min;
	return (0);
}


int		main(int argc, char **argv)
{
	t_frct	frct;

	if (argc == 1)
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
		mlx_hook(frct.win, 4, 0, mouse_zoom ,frct);
	//	mlx_hook(frct.win, 5, 0,       ,frct);
		mlx_hook(frct.win, 6, 0, get_coordinates ,&frct);
		mlx_loop(frct.mlx);
	}
	ft_putendl_fd("Usage : ./frct <filename>", 2);
	return (0);
}
