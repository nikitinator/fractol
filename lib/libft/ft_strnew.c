/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:29:09 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/04 17:46:41 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *newstr;
	char *retnewstr;

	if (!(newstr = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	retnewstr = newstr;
	while (size + 1 > 0)
	{
		*newstr++ = '\0';
		size--;
	}
	return (retnewstr);
}
