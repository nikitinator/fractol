/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_show_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:23:38 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/22 20:25:14 by snikitin         ###   ########.fr       */
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

void	toggle_space(t_frct *frct)
{
	if (frct->space_pressed)
		frct->space_pressed= 0;
	else
		frct->space_pressed = 1;
}
