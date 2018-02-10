/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:36:46 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:08:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *a;

	a = 0;
	while (*s)
	{
		if (*s == (char)c)
			a = (char *)s;
		s++;
	}
	if ((char)c == *s)
		return ((char*)s);
	else
		return (a);
}
