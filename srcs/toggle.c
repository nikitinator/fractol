/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_show_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:23:38 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/07 20:30:09 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	toggle_show_help(t_frct *frct)
{
	frct->show_help = !frct->show_help;
}

void	toggle_space(t_frct *frct)
{
	frct->space_pressed = !frct->space_pressed;
}
