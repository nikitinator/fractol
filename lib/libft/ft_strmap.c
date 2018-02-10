/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:03:17 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/05 13:08:00 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *newstr;
	char *retnewstr;

	if (s == NULL || s == NULL)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	retnewstr = newstr;
	while (*s)
		*newstr++ = (*f)(*s++);
	*newstr = '\0';
	return (retnewstr);
}
