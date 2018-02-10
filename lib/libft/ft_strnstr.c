/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:03:28 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/15 16:06:18 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t j;
	size_t i;

	if (*little == '\0')
		return ((char *)big);
	j = 0;
	while (big[j] && len)
	{
		i = 0;
		if (big[j] == little[i])
		{
			while (((big + j)[i] == little[i]) && little[i] != '\0' && len)
			{
				i++;
				len--;
			}
			if (little[i] == '\0')
				return ((char *)(big + j));
			len = len + i;
		}
		len--;
		j++;
	}
	return (NULL);
}
