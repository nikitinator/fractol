/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:21:28 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 14:37:45 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_key(int keycode, t_frct *frct)
{
	int						i;
	static t_func_key_hook	func[NUM_OF_BTNS] = {
		{BUT_ESC, exit_frct},
		{BUT_UP, mov_up_key}, {BUT_DOWN, mov_down_key},
		{BUT_RIGHT, mov_right_key}, {BUT_LEFT, mov_left_key},
		{BUT_PLU, zoom_in_key}, {BUT_MIN, zoom_out_key},
		{BUT_BIGG, incr_iteration_num}, {BUT_LESS, decr_iteration_num},
		{BUT_R, reset_frct},
		{BUT_SPACE, toggle_space},
		{BUT_F1, toggle_show_help},
		{BUT_1, set_color_1}, {BUT_2, set_color_2},
		{BUT_3, set_color_3}
		};

	i = 0;
	while (i < NUM_OF_BTNS && func[i].key != keycode)
		i++;
	if (i < NUM_OF_BTNS)
	{
		func[i].f(frct);
		scrn_upd(frct);
	}
	return (0);
}

static t_cmplx	get_cmplx(int x, int y, t_cmplx range, t_cmplx min)
{
	t_cmplx	coord;

	coord.re = (double)x / (IMG_WIDTH - 1) * range.re + min.re;
	coord.im = (double)y / (IMG_HEIGHT - 1) * range.im + min.im;
	return (coord);
}

int				mouse_zoom(int key, int x, int y, t_frct *frct)
{
	t_cmplx	mouse;
	t_cmplx	ratio;

	mouse = get_cmplx(x, y, frct->range, frct->min);
	if (key == 1 || key == 4)
	{
		frct->range.re *= (1 - frct->zoom_coeff);
		frct->range.im *= (1 - frct->zoom_coeff);
	}
	else if (key == 2 || key == 5)
	{
		frct->range.re *= (1 + frct->zoom_coeff);
		frct->range.im *= (1 + frct->zoom_coeff);
	}
	else
		return (0);
	ratio.re = (float)x / (IMG_WIDTH - 1);
	ratio.im = (float)y / (IMG_HEIGHT - 1);
	frct->min.re = mouse.re - frct->range.re * ratio.re;
	frct->max.re = mouse.re + frct->range.re * (1 - ratio.re);
	frct->min.im = mouse.im - frct->range.im * ratio.im;
	frct->max.im = mouse.im + frct->range.im * (1 - ratio.im);
	scrn_upd(frct);
	return (0);
}

int				mouse_trace(int x, int y, t_frct *frct)
{
	if (frct->space_pressed)
	{
		frct->julia_const = get_cmplx(x, y, frct->range, frct->min);
		scrn_upd(frct);
	}
	return (0);
}
