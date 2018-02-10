/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:28:23 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:29:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0 && (*(unsigned char *)src != (unsigned char)c))
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		n--;
	}
	if (n == 0)
		return (NULL);
	*((unsigned char *)dst++) = (unsigned char)c;
	return (dst);
}
