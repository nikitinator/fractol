/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:59:29 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/20 17:32:45 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char		*result;

	if (!(result = ft_strjoin(s1, s2)))
		return (NULL);
	free((void *)s1);
	free((void *)s2);
	return (result);
}
