/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:48:58 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:08:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;

	if (size <= (ft_strlen(dst) + 1))
		return (size + ft_strlen(src));
	l = ft_strlen(dst) + ft_strlen(src);
	if (l < size)
		size = l + 1;
	while (size > 1 && *dst != '\0')
	{
		size--;
		dst++;
	}
	while (size > 1 && *src != '\0')
	{
		size--;
		*dst++ = *src++;
	}
	if (size == 1)
		*dst = '\0';
	return (l);
}
