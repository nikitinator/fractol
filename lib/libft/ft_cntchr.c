/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:29:17 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/20 17:30:45 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_cntchr_count counts the number of occurences of char k in string str
*/

size_t	ft_cntchr(char *str, char k)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (*str)
		if (*str++ == k)
			n++;
	return (n);
}
