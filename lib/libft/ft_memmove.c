/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:50:47 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:30:02 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *retdst;

	retdst = dst;
	if (dst <= src || src + len < dst)
	{
		while (len--)
		{
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst++;
			src++;
		}
	}
	else
	{
		src += len - 1;
		dst += len - 1;
		while (len--)
		{
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst--;
			src--;
		}
	}
	return (retdst);
}
