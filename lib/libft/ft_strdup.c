/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:14:05 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:10:30 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy;
	char *ccopy;

	if (!(copy = (char *)malloc(ft_strlen(s1) + 1)))
		return (0);
	ccopy = copy;
	while (*s1 != '\0')
		*copy++ = *s1++;
	*copy = '\0';
	return (ccopy);
}
