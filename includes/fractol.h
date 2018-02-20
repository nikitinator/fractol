#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# include <sys/types.h>

# include "pthread.h"

# define THREADS 16 

# define X 0
# define Y 1
# define Z 2
# define PNT_CLR 3

# define PXL_CLR 2

# define T 3
# define R 2
# define G 1
# define B 0

# define IMG_WIDTH 1600
# define IMG_HEIGHT 1200

# define BUT_8 91
# define BUT_4 86
# define BUT_6 88
# define BUT_2 84
# define BUT_MIN 78
# define BUT_PLU 69
# define BUT_MUL 75
# define BUT_DIV 67
# define BUT_UP 126
# define BUT_DOWN 125
# define BUT_LEFT 123
# define BUT_RIGHT 124
# define BUT_UPLF 115
# define BUT_DWRI 119
# define BUT_A 0
# define BUT_S 1
# define BUT_D 2
# define BUT_Q 12
# define BUT_W 13
# define BUT_E 14
# define BUT_ESC 53
# define BUT_R 15
# define BUT_F1 122
# define BUT_BIGG 47
# define BUT_LESS 43
# define WHITE 0x00FFFFFF

//# define CHK_PIX(x, y) if((0 <= x && x< IMG_WIDTH) && (0 <= y && y<IMG_HEIGHT))
# define SET_PIX(x, y, i, c) *(int *)(i->arr+(x*i->by_pp+i->size_line*y)) = c

typedef double		t_point[4];
typedef int			t_pixel[3];
typedef float		t_matr3[9];

typedef union		u_color
{
	unsigned int	c_32;
	unsigned char	c_8[3];
}					t_color;

typedef struct		s_img
{
	void			*pnt_img;
	int				bi_pp;
	int				by_pp;
	int				size_line;
	int				endian;
	int				center[2];
	char			*arr;
}					t_img;

typedef struct		s_fract_data
{
	char			*name;
	long double		*max_im;
	long double		*min_im;
	long double		*max_re;
	long double		*mix_im;
}					t_fractal;

typedef struct		s_cmplx
{
	long double		im;
	long double		re;
}					t_cmplx;

typedef struct		s_frct
{
	int				fd;
	void			*mlx;
	void			*win;
	t_img			img;
	int				show_help;
	int			max_iterations;
	t_cmplx			max;
	t_cmplx			min;
	t_cmplx			range;
	t_cmplx			mov_coeff;
	long double		zoom_coeff;

	long double		im_factor;// mojno ubrat'
	long double		re_factor;//
	int				thread;
	void			(*f)();//

	pthread_cond_t	th_cond;
	size_t			milestones[THREADS + 1];
}					t_frct;



typedef struct		s_func_key_hook
{
	int				key;
	void			(*f)(t_frct *frct);
}					t_func_key_hook;


void	mov_up_key(t_frct *frct);
void	mov_down_key(t_frct *frct);
void	mov_left_key(t_frct *frct);
void	mov_right_key(t_frct *frct);
void	zoom_in_key(t_frct *frct);
void	zoom_out_key(t_frct *frct);

void				toggle_show_help(t_frct *frct);

void				change_clr_val(t_pixel *p, int clr, int val);
void				add_red(t_frct *frct);
void				add_grn(t_frct *frct);
void				add_blu(t_frct *frct);
void				sub_red(t_frct *frct);
void				sub_grn(t_frct *frct);
void				sub_blu(t_frct *frct);
void				reset_color(t_frct *frct);

void				incr_iteration_num(t_frct *frct);
void				decr_iteration_num(t_frct *frct);

void				apply_on_pntarr(t_frct *frct, double n,
		void (f)(t_point *, double));
void				apply_on_pxlarr(t_frct *frct, int clr, int val,
		void (f)(t_pixel *, int clr, int val));

void				exit_frct(t_frct *frct);
void				scrn_upd(t_frct *frct);

#endif
