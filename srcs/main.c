/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 14:43:51 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		launch_fractal_instance(int index_frct, int index_iter)
{
	t_frct		frct;
	t_thrd_inpt	mlst[THREAD_NUM];

	if (!(frct.mlx = mlx_init()))
		return (-1);
	if (!(frct.win = mlx_new_window(frct.mlx,
					IMG_WIDTH, IMG_HEIGHT, "Fractol by snikitin")))
		return (-1);
	set_milestones(mlst, &frct);
	init_frct(&frct, index_frct, index_iter);
	scrn_upd(&frct);
	mlx_hook(frct.win, KEY_PRESS, 0, handle_key, &frct);
	mlx_hook(frct.win, DESTROY_NOTIFY, 0, (int (*)(void *))exit_frct, &frct);
	mlx_hook(frct.win, BUTTON_PRESS, 0, mouse_zoom, &frct);
	mlx_hook(frct.win, MOTION_NOTIFY, 0, mouse_trace, &frct);
	mlx_loop(frct.mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		ppid;

	if (argc > 1 && !validate_params(argc, argv))
	{
		i = 0;
		while (++i < argc - 1 && ((ppid = fork()) == 0))
		{
			launch_fractal_instance(ft_atoi(argv[i]) / 100,
					ft_atoi(argv[i]) % 100);
			return (0);
		}
		launch_fractal_instance(ft_atoi(argv[i]) / 100,
					ft_atoi(argv[i]) % 100);
		return (0);
	}
	print_usage();
	return (0);
}
