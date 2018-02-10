/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:46:42 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:32:58 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char		*littlebeg;
	const char	*littlecopy;

	if (!(*(littlecopy = little)))
		return ((char *)big);
	littlebeg = NULL;
	while (*big)
	{
		if (*big == *little)
		{
			littlebeg = (char *)big;
			while ((*big == *little) && (*little != '\0'))
			{
				big++;
				little++;
			}
			if (*little == '\0')
				return (littlebeg);
			little = littlecopy;
			big = littlebeg;
		}
		big++;
	}
	return (NULL);
}
