/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:52:45 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:28:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void *a;

	a = b;
	while (0 < len)
	{
		*((unsigned char *)b++) = (unsigned char)c;
		len--;
	}
	return (a);
}
