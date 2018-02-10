/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:47:59 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/04 20:32:24 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_putnbr(unsigned int n)
{
	if (n / 10)
		rec_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		rec_putnbr((unsigned int)-n);
	}
	else
		rec_putnbr((unsigned int)n);
}
