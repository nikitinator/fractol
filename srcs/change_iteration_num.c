/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_iteration_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:17:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/20 17:32:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	incr_iteration_num(t_frct *frct)
{
	frct->max_iterations += 2;
	ft_putendl("test");
}


void	decr_iteration_num(t_frct *frct)
{
	if (frct->max_iterations != 0)
		frct->max_iterations -= 2;
}
