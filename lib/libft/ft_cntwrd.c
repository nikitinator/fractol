/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:47:43 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/20 14:04:37 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cntwrd(char *str)
{
	size_t	n;
	char	inword;

	if (!str)
		return (0);
	n = 0;
	inword = 0;
	while (*str)
	{
		if (!ft_iswhsp(*str) && !inword)
		{
			inword = 1;
			n++;
		}
		if (inword && ft_iswhsp(*(str + 1)))
			inword = 0;
		str++;
	}
	return (n);
}
