/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:09:56 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/05 13:08:43 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 == *s2 && n > 0)
	{
		if (*s1 == '\0')
			return (1);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (1);
	return (0);
}
