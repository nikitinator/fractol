/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:51:12 by snikitin          #+#    #+#             */
/*   Updated: 2017/10/27 16:01:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *copy;

	copy = dst;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = *src;
	return (copy);
}
