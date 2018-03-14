/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:31:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/14 14:16:33 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_variations(char *frct_name, int frct_index,
		t_frct_itr_data *data)
{
	int		i;

	i = 0;
	ft_putnbr(frct_index);
	ft_putstr(". ");
	ft_putstr(frct_name);
	ft_putstr(" :\n");
	while (++i < NUM_OF_VARIATIONS)
	{
		ft_putchar('\t');
		ft_putnbr(frct_index);
		if (i / 10 == 0)
			ft_putnbr(0);
		ft_putnbr(i);
		ft_putstr(" - ");
		ft_putstr(frct_name);
		ft_putchar(' ');
		ft_putendl(data[i].name);
	}
}

void	print_usage(void)
{
	t_frct_itr_data *data;
	int				i;
	int				fractal_index;

	data = get_frct_itr_data();
	fractal_index = 1;
	i = -1;
	ft_putendl_fd("Usage : ./fractol <fractal index>", 2);
	print_variations("Mandelbrot", fractal_index++, data);
	print_variations("Julia", fractal_index++, data);
}
