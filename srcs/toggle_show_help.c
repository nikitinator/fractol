/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_show_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:23:38 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/20 13:24:12 by snikitin         ###   ########.fr       */
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
