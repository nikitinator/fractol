/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:22:38 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 16:30:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# include <sys/types.h>
# include <pthread.h>

# define THREAD_NUM 16

# define X 0
# define Y 1
# define Z 2

# define T 3
# define R 2
# define G 1
# define B 0

# define IMG_WIDTH 1000
# define IMG_HEIGHT 800

# define MAX_ITER_DEFAULT 100
# define ZOOM_COEFF 25

# define NUM_OF_BTNS 15
# define NUM_OF_VARIATIONS 12

# define KEY_PRESS 2
# define BUTTON_PRESS 4
# define MOTION_NOTIFY 6
# define DESTROY_NOTIFY 17

# define DEFAULT_MAX_RE  1.2
# define DEFAULT_MIN_RE -1.2
# define DEFAULT_MAX_IM  1.0
# define DEFAULT_MIN_IM -1.0

# define BUT_MIN 78
# define BUT_PLU 69
# define BUT_UP 126
# define BUT_DOWN 125
# define BUT_LEFT 123
# define BUT_RIGHT 124
# define BUT_ESC 53
# define BUT_R 15
# define BUT_F1 122
# define BUT_BIGG 47
# define BUT_LESS 43
# define BUT_SPACE 49
# define BUT_F1 122
# define BUT_1 18
# define BUT_2 19
# define BUT_3 20

# define HELP_1  "              +"
# define HELP_2  "       space  |  julia constant value change with mouse"
# define HELP_3  "              |"
# define HELP_4  "         esc  |  exit"
# define HELP_5  "              |"
# define HELP_6  "           r  |  reset"
# define HELP_7  "              |"
# define HELP_8  "      arrows  |  move"
# define HELP_9  "              |"
# define HELP_10 " mouse wheel  |  zoom"
# define HELP_11 "              |"
# define HELP_12 "         + -  |  zoom"
# define HELP_13 "              |"
# define HELP_14 "         < >  |  change iteration number"
# define HELP_15 "              |"
# define HELP_16 "       1 - 3  |  change color palette"
# define HELP_17 "              +"

# define WHITE 0x00FFFFFF

# define SET_PIX(x, y, i, c) *(int *)(i->arr+(x*i->by_pp+i->size_line*y)) = c

typedef union		u_color
{
	unsigned int	c_32;
	unsigned char	c_8[4];
}					t_color;

typedef struct		s_img
{
	void			*pnt_img;
	int				bi_pp;
	int				by_pp;
	int				size_line;
	int				endian;
	char			*arr;
}					t_img;

typedef struct		s_cmplx
{
	long double		im;
	long double		re;
}					t_cmplx;

typedef struct		s_break
{
	t_cmplx			val;
	short			iter;
}					t_break;

typedef struct		s_frct_itr_data
{
	int				index;
	char			*name;
	t_cmplx			(*iter)(t_cmplx z, t_cmplx z2, t_cmplx to_add);
}					t_frct_itr_data;

typedef struct		s_frct
{
	void			*mlx;
	void			*win;
	t_img			img;
	short			show_help;
	short			space_pressed;
	short			is_julia;
	unsigned short	max_iterations;
	t_cmplx			max;
	t_cmplx			min;
	t_cmplx			range;
	t_cmplx			mov_coeff;
	long double		zoom_coeff;
	t_cmplx			julia_const;
	t_cmplx			step;
	t_cmplx			(*iter)(t_cmplx z, t_cmplx z2, t_cmplx to_add);
	int				(*get_pxl_clr)(int max_iter, t_break p);
	void			*mlst_p;
}					t_frct;

typedef struct		s_func_key_hook
{
	int				key;
	void			(*f)(t_frct *frct);
}					t_func_key_hook;

typedef struct		s_thrd_inpt
{
	t_frct			*frct;
	int				from;
	int				to;
}					t_thrd_inpt;

/*
** Main routine.
*/
void				init_frct(t_frct *frct, int	index_frct, int index_iter);
void				set_milestones(t_thrd_inpt *milestones, t_frct *frct);
t_frct_itr_data		*get_frct_itr_data(void);
int					validate_params(int argc, char **argv);
void				scrn_upd(t_frct *frct);
void				print_usage(void);
t_break				get_itr(t_cmplx (*iter)(), t_cmplx c, short max_iter,
		t_cmplx to_add);

/*
** Catching events.
*/
int					mouse_trace(int x, int y, t_frct *frct);
int					mouse_zoom(int key, int x, int y, t_frct *frct);
int					handle_key(int keycode, t_frct *frct);

/*
** Different mappins of fractal.
*/
t_cmplx				iterate_test(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_default(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_tricorn(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_julia(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_perp_brot(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_celtic_brot(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_celtic_bar(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_perp_celtic(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_burn_ship(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_heart_brot(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_perp_brn_shp(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_buffalo(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_celt_heart(t_cmplx z, t_cmplx z2, t_cmplx to_add);
t_cmplx				iterate_perp_buffalo(t_cmplx z, t_cmplx z2, t_cmplx to_add);

/*
** Coloring.
*/
int					get_pxl_clr_1(int max_iter, t_break p);
int					get_pxl_clr_2(int max_iter, t_break p);
int					get_pxl_clr_3(int max_iter, t_break p);

/*
** Button hooks.
*/
void				mov_up_key(t_frct *frct);
void				mov_down_key(t_frct *frct);
void				mov_left_key(t_frct *frct);
void				mov_right_key(t_frct *frct);
void				zoom_in_key(t_frct *frct);
void				zoom_out_key(t_frct *frct);
void				toggle_show_help(t_frct *frct);
void				toggle_space(t_frct *frct);
void				incr_iteration_num(t_frct *frct);
void				decr_iteration_num(t_frct *frct);
void				reset_frct(t_frct *frct);
void				exit_frct(t_frct *frct);
void				set_color_1(t_frct *frct);
void				set_color_2(t_frct *frct);
void				set_color_3(t_frct *frct);

#endif
