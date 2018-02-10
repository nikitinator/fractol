/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:20:54 by snikitin          #+#    #+#             */
/*   Updated: 2017/10/30 11:33:06 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *freshmem;

	if (!(freshmem = malloc(size)))
		return (NULL);
	ft_bzero(freshmem, size);
	return (freshmem);
}
