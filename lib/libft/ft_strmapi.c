/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:41:38 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/05 13:10:30 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*newstr;
	char				*retnewstr;
	unsigned int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if (!(newstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	retnewstr = newstr;
	while (s[i])
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (retnewstr);
}
