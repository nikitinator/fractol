/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/28 21:56:58 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		launch_fractal_instance(int index_frct, int index_iter)
{
		t_frct		frct;
		t_thrd_inp	milestones[THREAD_NUM]

		if (!(frct.mlx = mlx_init()))
			return (-1);
		if (!(frct.win = mlx_new_window(frct.mlx,
						IMG_WIDTH, IMG_HEIGHT, "Fractol by snikitin")))
			return (-1);
		set_milestones(milestones, &frct);
		init_frct(&frct, index_frct, index_iter);
		scrn_upd(milestones);
		mlx_hook(frct.win, 2, 0, handle_key, &frct);
		mlx_hook(frct.win, 17, 0, (int (*)(void *))exit_frct, &frct);
		mlx_hook(frct.win, 4, 0, mouse_zoom ,&frct);
	//	mlx_hook(frct.win, 5, 0,       ,frct);
		mlx_hook(frct.win, 6, 0, mouse_trace, &frct);
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
			ft_putendl("pizdoes");
			launch_fractal_instance(ft_atoi(argv[i]) / 100,
					ft_atoi(argv[i]) % 100);
			return(0);
		}
		launch_fractal_instance(ft_atoi(argv[i]) / 100,
					ft_atoi(argv[i]) % 100);
		return (0);
	}
	print_usage();
	return (0);
}
