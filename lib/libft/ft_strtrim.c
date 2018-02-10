/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:47:46 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/20 17:44:32 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	beg;
	size_t	end;
	char	*result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	beg = 0;
	while (ft_iswhsp(s[beg]))
		beg++;
	if (s[beg] == '\0')
		return (ft_strnew(0));
	while (ft_iswhsp(s[end]))
		end--;
	if (!(result = (char *)malloc(end - beg + 2)))
		return (NULL);
	i = 0;
	while (beg <= end && (s[beg] != '\0'))
		result[i++] = s[beg++];
	result[i] = '\0';
	return (result);
}
