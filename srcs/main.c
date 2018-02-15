/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/15 21:52:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
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

void		set_milestones(t_frct *frct)
{
	size_t	i;

	if (THREADS > 0)
	{
		i = 0;
		while (i < THREADS)
		{
			frct->milestones[i] = IMG_HEIGHT / THREADS * i;//
			//printf("i: %zu,frct->milestones[i]:%zu\n", i, frct->milestones[i]);
			i++;
		}
		//if (ftct->milestones[THREADS] > IMG_WIDTH)
		frct->milestones[THREADS] = IMG_HEIGHT;
		//printf("i: %zu,frct->milestones[i]:%zu\n", i, frct->milestones[i]);
	}
}


void	init_frct(t_frct *frct)
{
	init_frct_img(&frct->img, frct->mlx);
	frct->show_help = 0;
	frct->min_re = -2.0;
	frct->max_re =  1.0;
	frct->min_im = -1.2;
	frct->max_im =  1.2; // frct->min_im + (frct->max_re - frct->min_re) * IMG_HEIGHT / IMG_WIDTH;
	frct->zoom_re_val = 0.95 ;
	frct->zoom_im_val = 0.95;
	frct->mov_re_val = 0.05;
	frct->mov_im_val = 0.05;
	frct->max_iterations = 100;
	
	set_milestones(frct);

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


double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}


void apply_zoom(t_frct *frct, double mouse_re, double mouse_im, double zoomFactor)
{
     double interpolation = 1.0 / zoomFactor;
	 (void)interpolation;
     frct->min_re = interpolate(mouse_re, frct->min_re, interpolation);
     frct->min_im = interpolate(mouse_im, frct->min_im, interpolation);
     frct->max_re = interpolate(mouse_re, frct->max_re, interpolation);
     frct->max_im = interpolate(mouse_im, frct->max_im, interpolation);
}



int		mouse_zoom(int key, int x, int y, t_frct *frct)
{
	double mouse_re;
	double mouse_im;
	double ratio_im;
	double ratio_re;
	double range_re;
	double range_im;

	printf("x: %d\t\t y: %d\n", x, y);
//	printf("key: %d\t\t \n", key);
	mouse_re = (double)x / (IMG_WIDTH /
		(frct->max_re - frct->min_re)) + frct->min_re;
	mouse_im = (double)y / (IMG_HEIGHT /
			(frct->max_im - frct->min_im)) + frct->min_im;
	
	ratio_re = 1.0 / IMG_WIDTH  * (float)x;	
	ratio_im = 1.0 / IMG_HEIGHT * (float)y;  	

	printf("mouse_im: %f\n",mouse_im);
	printf("mouse_re: %f\n",mouse_re);

	printf("1 ratio_im: %f\n",ratio_im);
	printf("1 ratio_re: %f\n",ratio_re);

	range_re = (frct->max_re - frct->min_re);
	range_im = (frct->max_im - frct->min_im);
	//ratio_im = 1.0 / range_im  * mouse_im;	
	//ratio_re = 1.0 / range_re * mouse_re;  	
	//printf("2 ratio_im: %f\n", ratio_im);
	//printf("2 ratio_re: %f\n", ratio_re);
	printf("range_im: %f\n",range_im);
	printf("range_re: %f\n",range_re);
	//zoom_in_key(frct);

	if (key == 1 || key == 4)
	{
		//zoom_in_key(frct);
		range_re *= 0.95; 
		range_im *= 0.95; 
		
	}
	else if (key == 2 || key == 5)
	{
		//zoom_out_key(frct);
		range_re *= 1.05;
		range_im *= 1.05;
	}

	frct->min_re = mouse_re - range_re * ratio_re;
	frct->max_re = mouse_re + range_re * (1 - ratio_re);
	frct->min_im = mouse_im - range_im * ratio_im;
	frct->max_im = mouse_im + range_im * (1 - ratio_im);
	//frct->min_im = mouse_im - range_im * ratio_im;
	//frct->max_im = mouse_im + range_im * (1 - ratio_im);

	printf("frct->min_re:%Lf\n", frct->min_re);
	printf("frct->max_re:%Lf\n", frct->max_re);
	printf("frct->min_im:%Lf\n", frct->min_im);
	printf("frct->max_im:%Lf\n", frct->max_im);
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
